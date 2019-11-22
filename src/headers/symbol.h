//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_SYMBOL_H
#define BLASTER_SYMBOL_H
#define IDLEN 50

#include <uthash.h>
#define VAR_
#define STATIC_ARRAY
typedef struct __symbol__ symbol;
typedef symbol* symbol_p;
symbol_p tsymbol;


struct __symbol__ {
    char name[IDLEN];
    int type;
    union{
        //TODO
    };

    unsigned short is_dec : 1; // check if this entry (var,pointer,function,...) was declared
    unsigned short is_init : 1; // check if this entry (var,pointer,... ) was initialized

    UT_hash_handle hh; /* makes this structure hashable */
};


/**
 *              Insertion symbol into tsymbol(helper function)
 * @author : seyyid-ahmed lahmer
 * @brief : this function is used as helper to insert into tsymbol table [used in add_symbol_entry() : described below]
 *          it will allocate a new entry, then copy data into this new entry then perform insertion.
 *
 * @remarks : NO CHECK is perfomed in this function, EXCEPT for malloc return status,
 *            if malloc fails, exit is perfomed status 1 is returned
 *            IT DOES not deallocate symbol table if malloc fails TODO
 */
static void hash_add_str(symbol_p p);


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



#endif //BLASTER_SYMBOL_H
