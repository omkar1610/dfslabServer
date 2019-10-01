#include<sys/time.h>
#include<stdio.h>
#define GAP(start, end) ((end.tv_usec-start.tv_usec)+(end.tv_sec-start.tv_sec)*1000000)
void main()
{
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	
	/* START OF BLOCK */
	
	long int n, N, e, E, e_choose_i, E_e_choose_N_i, E_choose_N;
	float p_value = 0;
	long int i, var1, var2, var3, var4; // Temporary variables
	fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
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
	for(var1 = 1, var4 = 2; var4 <= E; var4++)
		var1 = var1 * var4; // Computes E!
	for(var2 = 1, var4 = 2; var4 <= N; var4++)
		var2 = var2 * var4; // Computes N!
	for(var3 = 1, var4 = 2; var4 <= E-N; var4++)
		var3 = var3 * var4; // Computes (E-N)!
	E_choose_N = var1/(var2*var3); // Computes (E choose N)
	p_value /= E_choose_N;
	
	/* END OF BLOCK */
	
	gettimeofday(&end_time, NULL);
	printf("p-value = %f (%d microseconds)", p_value, (int) GAP(start_time, end_time));
}