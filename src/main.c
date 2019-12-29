#include <stdio.h>
#include <zconf.h>
#include "headers/defs.h"

extern FILE *yyin, *yyout;

int main(int argc,char**argv) {
    globalData.symbol = create_shared_symbol("Blaster");
    globalData.finished = 0;
    globalData.symbol->optimized = -1;
    line_counter = 0;
    yyin = fopen("../test_sources/test1", "r");
    //yyout = fopen("../test_sources/res", "w");

    line_counter = 0;
    int ret = yyparse();
    printf("\n[+] Ret : %d",ret);
    //display_symbol_table();



    globalData.finished = 1;
    destroy_shared_symbol("Blaster",globalData.symbol);


    return 0;
}