#include "stdio.h"
#include "stdlib.h"
int main()
{
    float z[4] = {1.0,2.0,3.0,4.0};
    float t[4] = {6.0,7.0,8.0,9.0};

    int i;
    int a = 2;
    float tmp;
    for(i=0;i<=3;i++)
    {
        tmp = z[i];
        z[i] = t[i];
        t[i] = tmp;
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\t",t[i]);
    }
    return 0;
}