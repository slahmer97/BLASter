{
	int i;
	int ty[N], tx[N];
 for(i = 0; i < N; i++)
  {
	  ty[i] = 2*N + 1;
		for(j = N/4; j < 3*N/4;j++) 
		{
			ty[i] = (N + j)*tx[j] + ty[i];
		}
	}
}
