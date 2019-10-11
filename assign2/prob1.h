#include<sys/time.h>
#include<stdio.h>
#include <stdlib.h>
#define GAP(start, end) ((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1000000)
#define MIN(x,y) ((x)<(y)?(x):(y))
#define LLD long long int

void prog_orig(LLD n,LLD N,LLD e,LLD E)
{
	double p_value = 0;
	LLD i, var1, var2, var3, var4, e_choose_i, E_e_choose_N_i, E_choose_N; // Temporary variables
	
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
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
	printf("p-value = %lf \n", p_value);

	for(var1 = 1, var4 = 2; var4 <= E; var4++)
		var1 = var1 * var4; // Computes E!
	for(var2 = 1, var4 = 2; var4 <= N; var4++)
		var2 = var2 * var4; // Computes N!
	for(var3 = 1, var4 = 2; var4 <= E-N; var4++)
		var3 = var3 * var4; // Computes (E-N)!
	E_choose_N = var1/(var2*var3); // Computes (E choose N)
	printf("E_choose_N = %lld \n", E_choose_N);


	p_value /= E_choose_N;
	gettimeofday(&end_time, NULL);
	printf("p-value = %lf (%d microseconds)\n", p_value, (int) GAP(start_time, end_time));
}



LLD ncr(LLD **data, LLD n, LLD r)
{
	if(n<r) return 0;
	else if(r>(n>>1)) return data[n][n-r];
	else return data[n][r];
}
void prog_pascal(LLD n,LLD N,LLD e,LLD E)
{
	double p_value = 0;
	LLD e_choose_i, E_e_choose_N_i, E_choose_N;
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	if(n==0) 
	{
		p_value = 1;
		goto exit;
	}

	LLD **data = malloc((E+1)*sizeof(LLD*));
	for(int i = 1; i<=E ; i++)
	{
		data[i] = malloc(1 + (i>>1)*sizeof(LLD));
		data[i][0] = 1; //(n,0) = 1
	}

	// Using this formula to generate the pascal triangle
	// (n,r) = (n-1, r-1) + (n-1, r)
	for(int i = 2;i<=E;i++)
		for(int j = 1; j<=(i>>1);j++)
			if(i != 2*j)
				data[i][j] = data[i-1][j-1] + data[i-1][j];
			else
				data[i][j] = data[i-1][j-1] + data[i-1][j-1];

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
	
}

LLD ncr_store_fact(LLD *data, LLD n, LLD r)
{
	if(n<r) return 0;
	else if(r>(n>>1)) return ncr_store_fact(data, n, n-r);
	else return data[n]/(data[r]*data[n-r]);
}

void prog_store_fact(LLD n,LLD N,LLD e,LLD E)
{
	double p_value = 0;
	
	LLD e_choose_i, E_e_choose_N_i, E_choose_N;
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	if(n==0) 
	{
		p_value = 1;
		goto exit;
	}

	LLD *data = malloc((E+1)*sizeof(LLD));
	data[0] = 1;
	for(int i = 1; i<=E ; i++)
		data[i] = data[i-1]*i;

	
	if(n>=(N>>1))
	{	
		for(int i = n; i<=N;i++)
			p_value += ncr_store_fact(data, e,i) * ncr_store_fact(data, E-e,N-i);
		printf("p-value = %lf \n", p_value);
		printf("E_choose_N = %lld \n", ncr_store_fact(data,E,N));
		p_value /= ncr_store_fact(data,E,N);
	}
	else
	{
		for(int i = 0; i<n;i++)
			p_value += ncr_store_fact(data, e,i) * ncr_store_fact(data, E-e,N-i);
		printf("p-value = %lf \n", p_value);
		printf("E_choose_N = %lld \n", ncr_store_fact(data,E,N));

		p_value /= ncr_store_fact(data,E,N);
		p_value = 1 - p_value;
	} 
	exit:
	gettimeofday(&end_time, NULL);
	printf("p-value = %lf (%d microseconds)\n", p_value, (int) GAP(start_time, end_time));	
	
}

void prog_direct(LLD n,LLD N,LLD e,LLD E)
{
	double p_value = 0;
	LLD i, var1, var2, var3, var4, e_choose_i, E_e_choose_N_i, E_choose_N; // Temporary variables
	
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);

	for(var1 = 1, var4 = 2; var4 <= e; var4++)
		var1 = var1 * var4; // Computes e!
	for(var2 = 1, var4 = 2; var4 <= n; var4++)
		var2 = var2 * var4; // Computes i!
	for(var3 = 1, var4 = 2; var4 <= e-n; var4++)
		var3 = var3 * var4; // Computes (e-i)!

	e_choose_i = var1/(var2*var3); // Computes (e choose i)


	for(var1 = 1, var4 = 2; var4 <= (E-e); var4++)
		var1 = var1 * var4; // Computes (E-e)!
	for(var2 = 1, var4 = 2; var4 <= (N-n); var4++)
		var2 = var2 * var4; // Computes (N-i)!
	for(var3 = 1, var4 = 2; var4 <= ((E-e)-(N-n)); var4++)
		var3 = var3 * var4; // Computes ((E-e)-(N-i))!
	E_e_choose_N_i = var1/(var2*var3); // Computes ((E-e) choose (N-i))


	for(var1 = 1, var4 = 2; var4 <= E; var4++)
		var1 = var1 * var4; // Computes E!
	for(var2 = 1, var4 = 2; var4 <= N; var4++)
		var2 = var2 * var4; // Computes N!
	for(var3 = 1, var4 = 2; var4 <= E-N; var4++)
		var3 = var3 * var4; // Computes (E-N)!
	E_choose_N = var1/(var2*var3); // Computes (E choose N)

	LLD term1= (e_choose_i*E_e_choose_N_i)/E_choose_N;
	p_value  = term1;
	for(i = n+1; i <= N; i++)
	{
		term1 *= ((e-i)*(E-i-1))/((i+1)*(E-e-N+i+1)*E_choose_N);
		p_value += term1;
	}

	gettimeofday(&end_time, NULL);
	printf("p-value = %lf (%d microseconds)\n", p_value, (int) GAP(start_time, end_time));
}