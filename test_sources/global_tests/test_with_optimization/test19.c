#include "stdio.h"
#include "stdlib.h"
int main()
{
    float t[4];
    float z[4] = {1.0,1.0,1.0,1.0};
    int i;
    float a = 2.0,b = 1.0;
    for(i=0;i<=3;i++)
    {
        t[i] = a+(b/a);
    }

	for(i=0;i<=3;i++)
    {	
        t[i] = t[i] + z[i] * b ;
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\n",t[i]);
    }
    return 0;
}
