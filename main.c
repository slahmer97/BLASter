#include <stdio.h>


int main() {

    struct my_struct s ;
    s.name[0] = 'c';
    s.name[1] = 'z';
    s.id = 20;
    add_user(&s);

    struct my_struct *z;
    z = find_user(20);

    z++;

    printf("Hello, World!\n");
    return 0;
}