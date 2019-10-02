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
  
    if (n - r < r) 
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
	float p_value = 0;
	long int i, var1, var2, var3, var4; // Temporary variables
	//fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
	for(i = n; i <= N; i++)
	{
		// for(var1 = 1, var4 = 2; var4 <= e; var4++)
		// 	var1 = var1 * var4; // Computes e!
		// for(var2 = 1, var4 = 2; var4 <= i; var4++)
		// 	var2 = var2 * var4; // Computes i!
		// for(var3 = 1, var4 = 2; var4 <= e-i; var4++)
		// 	var3 = var3 * var4; // Computes (e-i)!
	
		// e_choose_i = var1/(var2*var3); // Computes (e choose i)


		// for(var1 = 1, var4 = 2; var4 <= (E-e); var4++)
		// 	var1 = var1 * var4; // Computes (E-e)!
		// for(var2 = 1, var4 = 2; var4 <= (N-i); var4++)
		// 	var2 = var2 * var4; // Computes (N-i)!
		// for(var3 = 1, var4 = 2; var4 <= ((E-e)-(N-i)); var4++)
		// 	var3 = var3 * var4; // Computes ((E-e)-(N-i))!
		// E_e_choose_N_i = var1/(var2*var3); // Computes ((E-e) choose (N-i))


		p_value += NcR(e,i)*NcR(E-e, N-i);
	}
	// for(var1 = 1, var4 = 2; var4 <= E; var4++)
	// 	var1 = var1 * var4; // Computes E!
	// for(var2 = 1, var4 = 2; var4 <= N; var4++)
	// 	var2 = var2 * var4; // Computes N!
	// for(var3 = 1, var4 = 2; var4 <= E-N; var4++)
	// 	var3 = var3 * var4; // Computes (E-N)!
	// E_choose_N = var1/(var2*var3); // Computes (E choose N)



	p_value /= NcR(E,N);
	gettimeofday(&end_time, NULL);
	printf("p-value = %f (%d microseconds)", p_value, (int) GAP(start_time, end_time));
}


void main()
{
	prog();
	// struct timeval start_time, end_time;
	// gettimeofday(&start_time, NULL);
	// long int n, N, e, E;
	// float p_value = 0;

	// fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
	// //Store E!
	// long int fact[E+1];
	// fact[0] = 1;
	// for(int i = 1; i<=E; i++)
	// 	fact[i] = i * fact[i-1];
	// if(n< N>>2) //add n to N
	// {
	// 	for(int i = n; i<=N; i++)
	// 		p_value += (fact[e]*fact[E-e])/(fact[i]*fact[e-i]*fact[N-i]*fact[E-N-e+i]);
	// 	p_value = (p_value*fact[N]*fact[E-N])/fact[E];
	// }
	// else // complement of 0 to n
	// {
	// 	for(int i = 0; i<n; i++)
	// 		p_value += (fact[e]*fact[E-e])/(fact[i]*fact[e-i]*fact[N-i]*fact[E-N-e+i]);
	// 	p_value = 1- (p_value*fact[N]*fact[E-N])/fact[E];
	// }
	// printf("p-value = %f (%d microseconds)", p_value, (int) GAP(start_time, end_time));
}