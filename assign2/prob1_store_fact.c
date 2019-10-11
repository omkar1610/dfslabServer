#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define GAP(start, end) ((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1000000)
#define MIN(x,y) ((x)<(y)?(x):(y))
#define TYPE long long int


TYPE ncr(TYPE *data, TYPE n, TYPE r)
{
	if(n<r) return 0;
	else if(r>(n>>1)) return ncr(data, n, n-r);
	else return data[n]/(data[r]*data[n-r]);
}

int main()
{
	double p_value = 0;
	TYPE n, N, e, E;
	fscanf(stdin, "%lld%lld%lld%lld", &n, &N, &e, &E);
	
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	if(n==0) 
	{
		p_value = 1;
		goto exit;
	}

	TYPE *data = malloc((E+1)*sizeof(TYPE));
	data[0] = 1;
	for(int i = 1; i<=E ; i++)
		data[i] = data[i-1]*i;

	
	if(n>=(N>>1))
	{	
		for(int i = n; i<=N;i++)
			p_value += ncr(data, e,i) * ncr(data, E-e,N-i);
		printf("p-value = %lf \n", p_value);
		printf("E_choose_N = %lld \n", ncr(data,E,N));
		p_value /= ncr(data,E,N);
	}
	else
	{
		for(int i = 0; i<n;i++)
			p_value += ncr(data, e,i) * ncr(data, E-e,N-i);
		printf("p-value = %lf \n", p_value);
		printf("E_choose_N = %lld \n", ncr(data,E,N));

		p_value /= ncr(data,E,N);
		p_value = 1 - p_value;
	} 
	exit:
	gettimeofday(&end_time, NULL);
	printf("p-value = %lf (%d microseconds)\n", p_value, (int) GAP(start_time, end_time));	
	return 0;
}