#include<sys/time.h>
#include<stdio.h>
#define GAP(start, end) ((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1000000)

long int gcd(long int n1, long int n2)
{
    if (n2 != 0)
       return gcd(n2, n1%n2);
    else 
       return n1;
}
long int NcR(long int n, long int r) 
{ 
    long int p = 1, k = 1; 
  
    if (n-r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            long int m = gcd(p, k);
            p /= m; k /= m; 
  	        n--;  r--; 
        } 
  	} 
  
    else
        p = 1; 
  
    return p;
} 


void prog()
{
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);

	long int n = 7, N = 26, e = 12, E = 52, e_choose_i, E_e_choose_N_i, E_choose_N;
	fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
	float p_value = 0;
	long int i, var1, var2, var3, var4; // Temporary variables
	//fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
	for(i = n; i <= N; i++)
		p_value += NcR(e,i)*NcR(E-e, N-i);
	p_value /= NcR(E,N);
	gettimeofday(&end_time, NULL);
	printf("p-value = %f (%d microseconds)", p_value, (int) GAP(start_time, end_time));
}


void main()
{
	prog();
}