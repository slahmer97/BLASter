#include <stdio.h>
#include <defs.h>
extern int line_counter;
extern FILE *yyin, *yyout;
extern symbol_p tsymbol;


int main() {
    tsymbol = 0;
    symbol_p glob = tsymbol;
    symbol p,p2;
    char name[50];
    memset(name,0,50);
    memset(p.name,0,50);
    memset(p2.name,0,50);
    p.name[0] = 'S';
    p.name[1] = 'S';
    p.name[2] = 'S';
    p.name[3] = 'S';
    p2.name[0] = 'S';
    p2.name[1] = 'S';
    p2.name[2] = 'S';
    p2.name[3] = 'S';
    p2.type = 13124;
    glob = tsymbol;

    name[0] = 'A';
    name[1] = 'S';
    name[2] = 'S';
    name[3] = 'S';
    p.type = 20;
    int ret = add_symbol_entry(&p);
    glob = tsymbol;
    p.type = 2200;
    ret =  add_symbol_entry(&p2);
    p2.name[0] = 'A';
    ret =  add_symbol_entry(&p2);
    symbol_p tmp = 0;
    ret = 0;
    ret = lookup_symbol_entry(name,&tmp);
    glob = tsymbol;
    //yyin = fopen("../test_sources/test1", "r");
    line_counter = 0;
    //yylex();
    // yyparse();
    return 0;
}