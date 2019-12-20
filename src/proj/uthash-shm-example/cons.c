#include <stdio.h>
#include "shared_table.h"

static void print_data(const Node *p)
{
    printf("%s\n", p->data);
}

int main()
{
    SharedTable st = SharedTable_subscribe("/testing");
    SharedTable_foreach(st, print_data);
    printf("-------\n");
    SharedTable_insert(st, "some other data");
    SharedTable_foreach(st, print_data);
}
