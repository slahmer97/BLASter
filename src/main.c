#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include "headers/defs.h"

extern FILE *yyin, *yyout;
extern char* file_out;
int main(int argc,char**argv) {
    char* file_in;
    file_in = argv[1];
    file_out = argv[2];
    int show = atoi(argv[3]);
    globalData.symbol = create_shared_symbol("Blaster");
    globalData.symbol->finished = 0;
    globalData.symbol->optimized = -1;
    line_counter = 0;
    yyin = fopen(file_in, "r");
    //yyout = fopen("../test_sources/res", "w");

    line_counter = 0;
    int ret = yyparse();
    printf("\n[+] Ret : %d",ret);
    //display_symbol_table();

    if(show == 10)
        display_symbol_table();

    globalData.symbol->finished = 1;

    sem_post(globalData.sem_prod_cons);
    sleep(1);
    destroy_shared_symbol("Blaster",globalData.symbol);


    return 0;
}