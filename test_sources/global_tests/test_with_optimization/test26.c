#include "stdio.h"
#include "stdlib.h"


int main()
{
    float t[4];
    float z[4];
    int i;
    int a = 2;
    
    for(i=0;i<=3;i++)
    {
        t[i] = 1;
    }
    
     for(i=0;i<=3;i++)
    {
        z[i] = 2;
    }
    
     for(i=0;i<=3;i++)
    {
        z[i] = t[i]*(a/2) + z[i];
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\n",t[i]);
    }
    return 0;
}
