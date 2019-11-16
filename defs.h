//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_DEFS_H
#define BLASTER_DEFS_H

#define IDLEN 50
#include <uthash.h>
enum {
  VARIABLE,
  FUNCTON,
  PARAMETER,

};
typedef struct __symbol__ symbol;
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


#endif //BLASTER_DEFS_H
