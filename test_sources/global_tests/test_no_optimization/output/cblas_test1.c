#include "stdio.h"
#include "stdlib.h"
#include "cblas.h"
int main()
{
int i; int N=20; int ty[20]; int tx[20];
for(i=0; i<=N/2; i++)
{tx[i]=1;}
for(i=N/2; i<N; i++)
{tx[i]=2+i;}
return 0 ;
}