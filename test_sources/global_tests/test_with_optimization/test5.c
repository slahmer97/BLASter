#include "stdio.h"
#include "stdlib.h"
int main()
{
    float t[4];
    float z[4] = {1.0,2.0,3.0,4.0};
    int i;
    int a = 2;
    for(i=0;i<=3;i++)
    {
        t[i] = 1;
    }
    for(i=0;i<=3;i++)
    {
        t[i] = a*t[i]+z[i]*a;
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\t",t[i]);
    }
    return 0;
}