//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_SYMBOL_H
#define BLASTER_SYMBOL_H

#include <uthash.h>
#include <defs.h>

typedef struct __symbol__ symbol;
typedef symbol* symbol_p;
typedef struct __symbol_entry_variable__ se_var;

struct __symbol__ {
    char name[IDLEN];
    union{
        //TODO
    };

    UT_hash_handle hh; /* makes this structure hashable */
};

struct __symbol_entry_variable__{

};
struct __symbol_entry_function__{

};
struct __symbol__entry_parameter__{

};

symbol_p users = NULL;

int add_symbol_entry(symbol_p);
symbol_p lookup_symbol_entry(const char*);




#endif //BLASTER_SYMBOL_H
