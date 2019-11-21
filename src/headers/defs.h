//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_DEFS_H
#define BLASTER_DEFS_H





int line_counter;


int yyerror(const char *str);
int yywrap(void);
int yyparse(void);
int yylex(void);


//TODO ALL public functions


#endif //BLASTER_DEFS_H
