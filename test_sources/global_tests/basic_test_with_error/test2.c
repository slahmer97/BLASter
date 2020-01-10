#include "stdio.h"
#include "stdlib.h"
#include "cblas.h"


int main()
{
	int t[80][100], b[20][10];
	float a = 4.3;
	float c = 2.2;
	sum = a+c;
	for(int i=0;i<80;i++)
	{
		for(int k=0;k<100;k++)
		{
			t[i][k] = sum*i+k;
		}
		
	}
	return 0;
}
