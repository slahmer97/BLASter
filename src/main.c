#include <stdio.h>
#include <defs.h>
extern int line_counter;
extern FILE *yyin, *yyout;


int main() {
    globalData.symbol = create_shared_symbol("Blaster");

    tsymbol = 0;
    line_counter = 0;
    yyin = fopen("../test_sources/test1", "r");
    line_counter = 0;
    yyparse();
    display_symbol_table();






   //sem_post(globalData.sem_symbol);

    destroy_shared_symbol("Blaster",globalData.symbol);


    return 0;
}