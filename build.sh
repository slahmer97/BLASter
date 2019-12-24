flex grammar/c_lex.l && yacc -d grammar/c_syn.y && mv lex.yy.c src/lex.yy.c && mv y.tab.c src/y.tab.c && mv y.tab.h src/headers/y.tab.h


