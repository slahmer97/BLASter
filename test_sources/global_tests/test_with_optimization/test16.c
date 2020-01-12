#include "stdio.h"
#include "stdlib.h"
int main()
{
    float t[4];
    float ww[20];
    float z[4] = {1.0,2.0,3.0,4.0};
    int i;
    int a = 2,b=20,c=33;ssd
    for(i=0;i<=3;i++)
    {
        t[i] = 10*a+c/(b*c);
    }
    for(i=0;i<=19;i++)
    {
        ww[i] = t[1]+t[3]*10;
    }
    for(i=0;i<=19;i++)
    {
        ww[i] = ww[i]*(a*b*c/d);
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\t",t[i]);
    }
    return 0;
}