//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_SYMBOL_H
#define BLASTER_SYMBOL_H
#define IDLEN 50

#include <uthash.h>

typedef struct __symbol__ symbol;
typedef symbol* symbol_p;


struct __symbol__ {
    char name[IDLEN];
    union{
        //TODO
    };

    short is_dec : 1; // check if this entry (var,pointer,function,...) was declared
    short is_init : 1; // check if this entry (var,pointer,... ) was initialized

    UT_hash_handle hh; /* makes this structure hashable */
};

//symbol_p users = NULL;

int add_symbol_entry(symbol_p);
symbol_p lookup_symbol_entry(const char*);




#endif //BLASTER_SYMBOL_H
