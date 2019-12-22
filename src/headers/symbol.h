//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_SYMBOL_H
#define BLASTER_SYMBOL_H
#define IDLEN 50

#include <uthash.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
typedef struct __symbol__ symbol;
typedef symbol* symbol_p;
struct global_data globalData;
symbol_p tsymbol;

#define VAR_SYM 999999
#define VAR_ARR 999999
#define DIM_MAX 10 //TODO change later to dynamic

struct __symbol__ {
    char name[IDLEN];
    int type;
    union{
        //TODO
        struct __sym_var__{
            unsigned int type;
        }var;

        struct __sym_arr_{
            unsigned int type;
            unsigned int is_static :1;
            int dimention_m;
            int dimention_p;
            int size[10];
        }arr;
        struct __symbol__* inner_tsym;
    };

    unsigned short is_dec : 1; // check if this entry (var,pointer,function,...) was declared
    unsigned short is_init : 1; // check if this entry (var,pointer,... ) was initialized



    unsigned short is_used:1;
};


#define N 1000
#define CODE_LEN 100000
struct shared_symbol{
    int count;
    symbol entries[N];

    char code_space[CODE_LEN];
};


struct global_data{
    sem_t * sem_symbol;
    struct shared_symbol* symbol;

    char* code;
    sem_t * sem_prod_cons;


};





struct shared_symbol* create_shared_symbol(char* name);
void destroy_shared_symbol(char*name,struct shared_symbol* ret);
struct shared_symbol* subscribe_shared_symbol(char*name);
void unsubscribe_shared_symbol( struct shared_symbol* ret);


/**
 *              Insertion symbol into tsymbol
 *
 * @author : seyyid-ahmed lahmer
 * @brief : this is the main function used insert symbol structure in the global symbol table.
 *
 * @param p : this is pointer to symbol structure to be inserted in the global symbol table
 * @return if the entry does not exist, insertion will be performed and 1 will be returned
 *         else (there exist already an entry with the corresponding index), insertion will
 *         not be performed, 0 will be returned.
 */
int add_symbol_entry(symbol_p);

/**
 * @author : seyyid-ahmed lahmer
 * @brief this function takes a variable name(index), the result will be passed in out param as
 *        a pointer to the corresponding entry in symbol table (if found), else out = null
 * @param name : used as an index in symbol_hash table,
 * @param out : pointer of symbol_p which will be holding a pointer to the corresponding entry in symbol table
 * @return this function returns 1 if it finds the coresponding entry, else 0 will be returned
 */
int lookup_symbol_entry(const char*,symbol_p* out);

void display_symbol_table(void);

/**
 *
 * @param symbolP
 */
void copy_name(symbol_p symbolP,const char*, unsigned int len);



#endif //BLASTER_SYMBOL_H
