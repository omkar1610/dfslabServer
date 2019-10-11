#include "prob1.h"

void main()
{
	LLD n, N , e , E , e_choose_i, E_e_choose_N_i, E_choose_N;
	fscanf(stdin, "%lld%lld%lld%lld", &n, &N, &e, &E);

	printf("\n");
	printf("\tOriginal:\n\n"); prog_orig(n,N,e,E);
	printf("\tOriginal:\n\n"); prog_orig(n,N,e,E);
	printf("\tPascal:\n\n"); prog_pascal(n,N,e,E);
	printf("\tFact Store:\n\n"); prog_store_fact(n,N,e,E);
	printf("\tDirect:\n\n"); prog_direct(n,N,e,E);
}