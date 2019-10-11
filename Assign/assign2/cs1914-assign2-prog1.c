/*
*	Original Program = The code which was to be modified
*	Program_direct = The modified funtion, which performs better in terms of time taken by it.
*	
*	Tried one alternative as finding nCr using pascal triangle, which handles quite large values but the time taken by this is not imptoved much.

*/
#include<sys/time.h>
#include<stdio.h>
#include <stdlib.h>
#define GAP(start, end) ((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1000000)
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define LLD long long int

void Original_Program(LLD n,LLD N,LLD e,LLD E)
{
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	double p_value = 0;
	LLD i, var1, var2, var3, var4, e_choose_i, E_e_choose_N_i, E_choose_N; // Temporary variables
	
	for(i = n; i <= N; i++)
	{
		for(var1 = 1, var4 = 2; var4 <= e; var4++)
			var1 = var1 * var4; // Computes e!
		for(var2 = 1, var4 = 2; var4 <= i; var4++)
			var2 = var2 * var4; // Computes i!
		for(var3 = 1, var4 = 2; var4 <= e-i; var4++)
			var3 = var3 * var4; // Computes (e-i)!

		e_choose_i = var1/(var2*var3); // Computes (e choose i)


		for(var1 = 1, var4 = 2; var4 <= (E-e); var4++)
			var1 = var1 * var4; // Computes (E-e)!
		for(var2 = 1, var4 = 2; var4 <= (N-i); var4++)
			var2 = var2 * var4; // Computes (N-i)!
		for(var3 = 1, var4 = 2; var4 <= ((E-e)-(N-i)); var4++)
			var3 = var3 * var4; // Computes ((E-e)-(N-i))!
		E_e_choose_N_i = var1/(var2*var3); // Computes ((E-e) choose (N-i))


		p_value += e_choose_i*E_e_choose_N_i;
	}
	// printf("p-value = %lf \n", p_value);

	for(var1 = 1, var4 = 2; var4 <= E; var4++)
		var1 = var1 * var4; // Computes E!
	for(var2 = 1, var4 = 2; var4 <= N; var4++)
		var2 = var2 * var4; // Computes N!
	for(var3 = 1, var4 = 2; var4 <= E-N; var4++)
		var3 = var3 * var4; // Computes (E-N)!
	E_choose_N = var1/(var2*var3); // Computes (E choose N)
	// printf("E_choose_N = %lld \n", E_choose_N);


	p_value /= E_choose_N;
	gettimeofday(&end_time, NULL);
	printf("p-value = %lf (%d microseconds)\n", p_value, (int) GAP(start_time, end_time));
}


LLD gcd(LLD a, LLD b) 
{
    while( b!=0 )
    {
        a = a % b;
        if( a==0 ) 
        	return b;
        b = b % a;
    }
    return a;
}

LLD giveNcR(LLD n, LLD r) 
{ 
    LLD p = 1, k = 1; 
  
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) 
    { 
        while (r) 
        { 
            p *= n; k *= r; 

            LLD m = gcd(p, k); 
            p /= m;	k /= m; 
  
            n--;	r--; 
        } 
    } 
  
    else
        p = 1; 
    return p; 
}


void Program_direct(LLD n,LLD N,LLD e,LLD E)
{
	/*
	*	1. p_value = (e i)*(E-e N-i)
	*		For both these combination to be defined, the range of valid i is,
	*				e-(E-N) <= i <= e
	*	2. So my range of i is not [0,N], instead it is [max(0, e-E+n), min(e,N)]
	*		That's the start and end variable in the code.
	*
	*	3. We need sum from n to N, there are 3 cases,
	*		i)	n>end, then the value is 0
	*		ii)	n<=start, then the value is 1
	*		iii)n in (start, end] here we have 2 more subcases
	*				a)	either start to n-1 OR
	*				b)	n to end, depending on which involves less calculation
	*	4.	And (e,i+1)*(E-e, N-i-1) = (e,i)*(E-e, N-i)*(e-i)*(N-i)/((i+1)*(E-e-N+i+1)); This avoids finding nCr for each iteration

	*/

	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);

	double p_value = 0;
	LLD E_choose_N,i;	

	LLD start = MAX(0, e-E+N), end = MIN(N,e);

	if(n>end) p_value = 0;
	
	else if(n<=start)	p_value = 1;

	else // n b/w (start, end]
	{
		LLD len1 = (n-1)-start+1, len2 = end-n +1;

		E_choose_N = giveNcR(E,N);
		if(len1>=len2)
		{
			//Go with second half
			start = n;

			i = start;
			LLD term = giveNcR(e,i)*giveNcR(E-e,N-i);
			p_value = term;
			for(;i<end;i++)
			{
				term *= (e-i)*(N-i);
				term /= (i+1)*(E-e-N+i+1);
				p_value += term;
			}
			p_value /= E_choose_N;

		}
		else
		{
			//Go with first half
			end = n-1;
			i = start;
			LLD term = giveNcR(e,i)*giveNcR(E-e,N-i);
			p_value = term;
			for(;i<end;i++)
			{
				term *= (e-i)*(N-i);
				term /= (i+1)*(E-e-N+i+1);
				p_value += term;
			}
			p_value /= E_choose_N;
			p_value = 1- p_value;
		}
	}

	gettimeofday(&end_time, NULL);
	printf("p-value = %lf (%d microseconds)\n", p_value, (int) GAP(start_time, end_time));
}

void main()
{
	LLD n, N , e , E , e_choose_i, E_e_choose_N_i, E_choose_N;
	fscanf(stdin, "%lld%lld%lld%lld", &n, &N, &e, &E);

	//First function always takes more time
	//I am not sure of the reason
	//The following timing shouldn't be consodered
	printf("\nOriginal:\t"); Original_Program(n,N,e,E);

	//Here onwards compare the timings
	printf("\nOriginal:\t"); Original_Program(n,N,e,E);
	printf("\nDirect:\t"); Program_direct(n,N,e,E);
}