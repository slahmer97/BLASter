// Created by slahmer on 11/16/19.
#include <stdio.h>
#include "headers/symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
int shm_fd = -1;
struct shared_symbol* create_shared_symbol(char* name){
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    printf("shm_fd : %d\n",shm_fd);
    if (shm_fd < 0) {
        perror("create_shared_symbol()");
        return (struct shared_symbol*)0;
    }

    sem_t *sem_id = sem_open("Blaster_sem", O_CREAT, 0666,0);
    if (sem_id == SEM_FAILED){
        perror("Blaster_sem  : [sem_open] Failed\n");
        return (struct shared_symbol*)0;
    }
    globalData.sem_symbol = sem_id;


    sem_id = sem_open("Blaster_sem_prod_cons", O_CREAT, 0666, 0);
    if (sem_id == SEM_FAILED){
        perror("Blaster_sem_prod_cons  : [sem_open] Failed\n");
        return (struct shared_symbol*)0;
    }
    globalData.sem_prod_cons = sem_id;

    ftruncate(shm_fd, sizeof(struct shared_symbol));
    struct shared_symbol* ret =(struct shared_symbol*)mmap(0,sizeof(struct shared_symbol), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    memset((void*)ret,0,sizeof(struct shared_symbol));
    return ret;
}
struct shared_symbol* subscribe_shared_symbol(char*name){
    shm_fd = shm_open(name, O_RDWR, 0666);
    printf("shm_fd : %d\n",shm_fd);


    if (shm_fd < 0) {
        perror("shm_open()");
        return (struct shared_symbol*)0;
    }
    globalData.sem_symbol = sem_open("Blaster_sem", O_CREAT, 0666);
    if (globalData.sem_symbol == SEM_FAILED){
        perror("Child   : [sem_open] Failed\n");
        return (struct shared_symbol*)0;
    }
    globalData.sem_prod_cons = sem_open("Blaster_sem_prod_cons", O_CREAT, 0666);
    if (globalData.sem_prod_cons == SEM_FAILED){
        perror("Child   : [sem_open] Failed\n");
        return (struct shared_symbol*)0;
    }
    struct shared_symbol* ret =(struct shared_symbol*)mmap(0, sizeof(struct shared_symbol), PROT_WRITE|PROT_READ, MAP_SHARED, shm_fd, 0);
    return ret;
}
void destroy_shared_symbol(char* name, struct shared_symbol* ret){
    if(ret != 0)
        munmap((void*)ret, sizeof(struct shared_symbol));
    if(shm_fd > 0)
        close(shm_fd);
    shm_unlink(name);

    if (sem_close(globalData.sem_symbol) != 0){
        perror("Blaster_sem  : [sem_close] Failed\n"); return;
    }
    if (sem_close(globalData.sem_prod_cons) != 0){
        perror("Blaster_sem_prod_cons  : [sem_close] Failed\n"); return;
    }
    if (sem_unlink("Blaster_sem") < 0){
        printf("Blaster_sem  : [sem_unlink] Failed\n"); return;
    }
    if (sem_unlink("Blaster_sem_prod_cons") < 0){
        printf("Blaster_sem_prod_cons  : [sem_unlink] Failed\n"); return;
    }
    memset(&globalData,0,sizeof(struct global_data));
}
void unsubscribe_shared_symbol(){
    munmap((void*)globalData.symbol, sizeof(struct shared_symbol));
    close(shm_fd);
    if (sem_close(globalData.sem_symbol) != 0){
        perror("Parent  : [sem_close] Failed\n"); return;
    }
    if (sem_close(globalData.sem_prod_cons) != 0){
        perror("Parent  : [sem_close] Failed\n"); return;
    }
    memset(&globalData,0,sizeof(struct global_data));

}

int add_symbol_entry(symbol_p p){
    symbol_p tmp = 0;
    int ret = lookup_symbol_entry(p->name,&tmp);
    if (ret == 1)
        return 0;
    symbol_p entry = 0;
    for (int i = 0; i < N ; ++i)
        if(globalData.symbol->entries[i].is_used == 0){
            globalData.symbol->entries[i].is_used = 1;
            entry = &globalData.symbol->entries[i];
            break;
        }
    if(entry == 0)
        return 0;

    globalData.symbol->count++;
    memcpy(entry,p,sizeof(symbol));
    entry->is_used = 1;
    return 1;
}
int lookup_symbol_entry(const char* name,symbol_p *out){
    if(globalData.symbol->count == 0){
        out=(symbol_p *)0;
        return 0;
    }
    for (int i = 0; i < N ; ++i)
        if(globalData.symbol->entries[i].is_used && strncmp(globalData.symbol->entries[i].name,name,50)==0){
            *out = &globalData.symbol->entries[i];
            return 1;
        }

    out=(symbol_p *)0;
    return 0;
}
void copy_name(symbol_p symbolP,const char* name, unsigned int len){
    unsigned int min = (len < IDLEN) ?len:IDLEN;
    memset(symbolP->name,0,IDLEN);
    for (unsigned int i = 0; i < min ; ++i)
        symbolP->name[i] = name[i];
}
void display_symbol_table(void){
    symbol_p s;

    printf("\n---------------------Symbole-Table-----------------------\n");
    for(int i=0;i<N;i++) {
        s = &globalData.symbol->entries[i];
        if(s->is_used == 0)
            continue;
        if(s->type == VAR_ARR){
            printf("name :  %s -- is_dec : %d -- is_init : %d -- type : Arr -- Direct_point : %d -- Vec_pointer : %d --- ", s->name,s->is_dec,s->is_init,s->arr.dimention_m,s->arr.dimention_p);
            printf("[");
            for (int j = 0; j < 4; ++j){
                if(j == 3)
                    printf("%d",s->arr.size[j]);
                else
                    printf("%d,",s->arr.size[j]);

            }
            printf("]\n");
        }
        else
            printf("name :  %s -- is_dec : %d -- is_init : %d -- type : %d\n", s->name,s->is_dec,s->is_init,s->type);
        printf("---------------------------------------------------------\n");
    }
}
