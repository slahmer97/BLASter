#include "shared_table.h"
#include <assert.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct SharedGuts {
    void *base;
    size_t size;
    pthread_mutex_t mutex;
    char *next_allocation;
    Node *hash;
    //symbol_p tsymbol;
} SharedGuts;

static SharedGuts *SharedGuts_create(void *base, size_t size)
{
    SharedGuts *guts = base;
    pthread_mutexattr_t attr;
    int rc = pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    assert(rc == 0);
    rc = pthread_mutex_init(&guts->mutex, &attr);
    assert(rc == 0);
    guts->base = base;
    guts->size = size;
    guts->next_allocation = (char *)(guts + 1);
    guts->hash = NULL;
    return guts;
}

SharedTable SharedTable_create(const char *name, size_t arena_size)
{
    SharedTable t;
    t.fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    assert(t.fd > 0);
    t.size = arena_size;
    ftruncate(t.fd, t.size);
    t.base = mmap(0, t.size, PROT_READ | PROT_WRITE, MAP_SHARED, t.fd, 0);
    assert(t.base != MAP_FAILED);
    t.guts = SharedGuts_create(t.base, t.size);
    return t;
}

SharedTable SharedTable_subscribe(const char *name)
{
    SharedTable t;
    t.fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    assert(t.fd > 0);
    SharedGuts *guts = mmap(NULL, sizeof (SharedGuts), PROT_READ | PROT_WRITE, MAP_SHARED, t.fd, 0);
    assert(guts != MAP_FAILED);
    void *where = guts->base;
    t.size = guts->size;
    munmap(guts, sizeof (SharedGuts));
    t.base = mmap(where, t.size, PROT_READ | PROT_WRITE, MAP_SHARED, t.fd, 0);
    t.guts = t.base;
    assert(t.guts->base == t.base);
    assert(t.guts->size == t.size);
    return t;
}

void SharedTable_unsubscribe(SharedTable t)
{
    munmap(t.base, t.size);
    close(t.fd);
}

static void *SharedTable_malloc(SharedTable t, size_t size)
{
    void *ptr = t.guts->next_allocation;
    if ((ptr - t.base) + size <= t.size) {
        t.guts->next_allocation += size;
    } else {
        assert(0 && "out of memory");
        ptr = NULL;
    }
    return ptr;
}

static char *SharedTable_strdup(SharedTable t, const char *s)
{
    char *dest = SharedTable_malloc(t, strlen(s) + 1);
    strcpy(dest, s);
    return dest;
}

static void SharedTable_free(SharedTable t, void *p)
{
    // no-op
}

void SharedTable_foreach(SharedTable t, void (*callback)(const Node *))
{
    for (struct Node *p = t.guts->hash; p != NULL; p = p->hh.next) {
        callback(p);
    }
}

int SharedTable_insert(SharedTable t, const char *newdata)
{
#undef uthash_malloc
#define uthash_malloc(sz) SharedTable_malloc(t, sz)
    Node *p = NULL;
    HASH_FIND_STR(t.guts->hash, newdata, p);
    if (p != NULL) {
        // The key is already in the hash.
        return 0;
    } else {
        p = SharedTable_malloc(t, sizeof *p);
        p->data = SharedTable_strdup(t, newdata);
        HASH_ADD_KEYPTR(hh, t.guts->hash, newdata, strlen(newdata), p);
        return 1;
    }
#undef uthash_malloc
}

/* Return 1 if the element was removed, or 0 if it wasn't found. */
int SharedTable_remove(SharedTable t, const char *newdata)
{
#undef uthash_malloc
#define uthash_malloc(sz) SharedTable_malloc(t, sz)
    Node *p = NULL;
    HASH_FIND_STR(t.guts->hash, newdata, p);
    if (p != NULL) {
        HASH_DEL(t.guts->hash, p);
        SharedTable_free(t, p->data);
        SharedTable_free(t, p);
        return 1;
    } else {
        return 0;
    }
#undef uthash_malloc
}
