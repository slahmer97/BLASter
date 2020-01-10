{
int N = 1000;
int M = 2000;
int j,k,a=4;
for (i = 0; i < N; i++) 
{
    for (j = 0; j < M; j++) 
    {    
        for (k = 0; k < 100; k += 2) 
        {
            t[k] = i+j-k*a;
            t[k + 1] = k*a;
        }
    } 
}
}
