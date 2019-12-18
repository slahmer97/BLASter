#pragma once

#include <stdlib.h>
#include "uthash.h"

typedef struct SharedTable {
    int fd;
    void *base;
    size_t size;
    struct SharedGuts *guts;  // actually points into the shared memory segment
} SharedTable;

typedef struct Node {
    char *data;
    UT_hash_handle hh;
} Node;

SharedTable SharedTable_create(const char *name, size_t arena_size);
SharedTable SharedTable_subscribe(const char *name);
void SharedTable_unsubscribe(SharedTable t);
void SharedTable_foreach(SharedTable t, void (*callback)(const Node *));
int SharedTable_insert(SharedTable t, const char *newdata);
int SharedTable_remove(SharedTable t, const char *newdata);
