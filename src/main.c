#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include "headers/defs.h"

extern FILE *yyin, *yyout;
extern char* file_out;
extern int display_ast;

int main(int argc, char**argv) {
     char* file_in = NULL;
     file_out = NULL;
     int arglen;
     int show = 0;
     display_ast = 0;
     char opt;
     while ((opt = getopt(argc, argv, "i:o:avt")) != -1) {
        switch (opt) {
          case 'a':
            display_ast = 1;
            break;
          case 'i':
            arglen = strlen(optarg);
            file_in = (char *) malloc(sizeof(char) * arglen);
            strncpy(file_in, optarg, arglen);
            break;
          case 'o':
            arglen = strlen(optarg);
            file_out = (char *) malloc(sizeof(char) * arglen);
            strncpy(file_out, optarg, arglen);
            break;
          case 'v':
            printf("TAHER Hussein\nLahmer Seyyid-Ahmed\nSerradj Elhadi\n");
            exit(EXIT_SUCCESS);
          case 't':
            show = 1;
            break;
        }
      }
    
    if (file_out == NULL) {
      fprintf(stderr, "NO output file given\n");
      exit(EXIT_FAILURE);
    }

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

    if(show == 1)
        display_symbol_table();
    globalData.symbol->finished = 1;

    sem_post(globalData.sem_prod_cons);
    sleep(1);
    destroy_shared_symbol("Blaster",globalData.symbol);


    return 0;
}
