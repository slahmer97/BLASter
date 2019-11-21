#include <stdio.h>
#include <defs.h>
extern int line_counter;
int main() {
    line_counter = 0;
    //return yylex();
    return yyparse();
}