//
// Created by slahmer on 11/16/19.
//

#include <stdio.h>
#include "symbol.h"


static int hash_find_str(const char* name,symbol_p* out){
    symbol_p tmp;
    HASH_FIND_STR(tsymbol,name,tmp);
    *out = tmp;
    if (*out == 0)
        return 0;
    else return 1;
}
static void hash_add_str(symbol_p p){
    symbol_p copy =(symbol_p)malloc(sizeof(symbol));
    if(!copy){
        fprintf(stderr,"[-] hash_add_str failed, couldn't malloc\n");
        exit(1);
    }
    memcpy(copy,p,sizeof(symbol));
    copy->is_dec = 0;
    copy->is_init = 0;
    copy->type  = -1;
    HASH_ADD_STR(tsymbol,name,copy);
}



int add_symbol_entry(symbol_p p){
    symbol_p tmp = 0;
    int ret = hash_find_str((const char*)p->name,&tmp);
    if(ret)
        return 0;
    hash_add_str(p);
    return 1;
}




int lookup_symbol_entry(const char* name,symbol_p *out){
    hash_find_str(name,out);
    if(out == 0){
        out = 0;
        return 0;
    }
    return 1;
}

void copy_name(symbol_p symbolP,const char* name, unsigned int len){
    unsigned int min = (len < IDLEN) ?len:IDLEN;
    memset(symbolP->name,0,IDLEN);
    for (unsigned int i = 0; i < min ; ++i)
        symbolP->name[i] = name[i];
}

void display_symbol_table(void){
    symbol_p s;

    for(s=tsymbol; s != NULL; s=s->hh.next) {
        if(s->type == VAR_ARR){
            printf("name :  %s -- is_dec : %d -- is_init : %d -- type : Arr -- Direct_point : %d -- Vec_pointer : %d --- ", s->name,s->is_dec,s->is_init,s->arr.dimention_m,s->arr.dimention_p);
            printf("[");
            for (int i = 0; i < 4; ++i){
                if(i == 3)
                    printf("%d",s->arr.size[i]);
                else
                    printf("%d,",s->arr.size[i]);

            }
            printf("]\n");
        }
        else
            printf("name :  %s -- is_dec : %d -- is_init : %d -- type : %d\n", s->name,s->is_dec,s->is_init,s->type);
    }
}

void destroy_symbol_table(void){
    symbol_p current_user, tmp;

    HASH_ITER(hh, tsymbol, current_user, tmp) {
        HASH_DEL(tsymbol,current_user);  /* delete; users advances to next */
        free(current_user);            /* optional- if you want to free  */
    }
}
