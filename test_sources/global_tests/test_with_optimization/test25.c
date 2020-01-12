#include "stdio.h"
#include "stdlib.h"


int main()
{
    float t[4];
    float z[4] = {1.0,1.0,1.0,1.0};
    int i;
    float a = 2.0,b = 1.0;
    float sum = a+b;
    for(i=0;i<=3;i++)
    {
        t[i] = sum;
    }

	for(i=0;i<=3;i++)
    {	
        t[i] =  z[i]+t[i]*2;
    }
	
    for(i=0;i<=3;i++)
    {
        printf("%f\n",t[i]);
    }
    return 0;
}
