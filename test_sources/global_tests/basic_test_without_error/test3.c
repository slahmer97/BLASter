#include "stdio.h"
#include "stdlib.h"
#include "cblas.h"
int main()
{
		int i =0,N=10,t[10],m[10];
	float k,l;
	i = N/2;
	N++;
	k = 2 * N + 1;
	l = 3*k/4;
	m[2] = l;
	t[5] = (N +5) * m[2];
	
	return 0;
}
