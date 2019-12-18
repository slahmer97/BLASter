#include <stdio.h>
#include "shared_table.h"

static void print_data(const Node *p)
{
    printf("%s\n", p->data);
}

int main()
{
    SharedTable st = SharedTable_create("/testing", 4000);
    SharedTable_insert(st, "some data");
    SharedTable_foreach(st, print_data);
}
