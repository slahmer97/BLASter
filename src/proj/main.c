#include <stdio.h>

#include "symbol.h"
extern symbol_p tsymbol;


int main() {
    tsymbol = 0;
    symbol a;
    a.name[0] = 'a';
    a.name[1] = 'a';
    a.name[2] = 'a';
    a.name[3] = 0;
    add_symbol_entry(&a);
    display_symbol_table();
    destroy_symbol_table();
    display_symbol_table();
    //detach the symbol
    return 0;
}
