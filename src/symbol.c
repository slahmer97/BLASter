//
// Created by slahmer on 11/16/19.
//

#include <stdio.h>
#include <symbol.h>


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
    for (unsigned int i = 0; i < min ; ++i)
        symbolP->name[i] = name[i];
}

void display_symbol_table(void){
    symbol_p s;

    for(s=tsymbol; s != NULL; s=s->hh.next) {
        printf("name %s\n", s->name);
    }
}