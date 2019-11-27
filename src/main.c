#include <stdio.h>
#include <defs.h>

extern int line_counter;
extern FILE *yyin, *yyout;
extern symbol_p tsymbol;


int main() {
    tsymbol = 0;
    line_counter = 0;
    yyin = fopen("../test_sources/test1", "r");
    line_counter = 0;
    yyparse();
    display_symbol_table();
    return 0;
}