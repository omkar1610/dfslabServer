#include <stdio.h>
#include <stdlib.h>
#define LLD long long int

void init(LLD ***a, int dim)
{
	*a = malloc(dim * sizeof(LLD *));
		for(int i=0; i<dim; i++) (*a)[i] = malloc(dim * sizeof(LLD));
}

void mult(LLD **a, LLD **b, LLD **c, int dim)// C = AxB
{
	for(int i=0;i<dim;i++)
		for(int j = 0;j<dim;j++)
		{
			c[i][j] = 0;
			for(int k=0;k<dim;k++)
				c[i][j] = c[i][j] +a[i][k]*b[k][j];
		}
}

void copy(LLD **a, LLD **b, int dim) //A = B Copy the matrix
{
	for(int i=0;i<dim ;i++)
		for(int j = 0;j<dim;j++)
			a[i][j] = b[i][j];
}

void display(LLD **a, int dim)// Print the matrix A
{
	for(int i=0;i<dim ;i++)
	{
		for(int j = 0;j<dim;j++)
			printf("%lld ", a[i][j]);
		printf("\n");
	}
}

void EXP(LLD **a, LLD **array, LLD **c, int n, int dim)// Find the exponent
{
	if(n == 0)
	{
		//Identity Matrix
		for(int i=0;i<dim ;i++)
			for(int j = 0;j<dim;j++)
				c[i][j] = i==j?1:0;
	}
	else if(n&1 == 0)// Even Power means A^n = (A^2)^(n/2)
	{
		mult(a,a,c,dim); // C = A^2
		copy(a,c,dim); // A = A^2
		EXP(a,array,c,n>>1,dim);
	}
	else// Odd n means A^n = A^(n-1)xA
	{
		EXP(a,array,c,n-1,dim);//C = A^n-1
		copy(a,c, dim);// A = A^n-1
		mult(a,array,c,dim);
	}
}

int main()
{
	int dim, n;
	scanf("%d%d",&dim, &n);

	LLD **a, **array, **c;
	init(&a, dim);init(&array, dim);init(&c, dim);
	
	for(int i=0;i<dim ;i++)
			for(int j = 0;j<dim;j++)
				scanf("%lld", &a[i][j]);

	copy(array, a, dim);//Store for odd power

	EXP(a,array,c,n,dim);
	display(c,dim);
	for(int i=0; i<dim; i++) free(a[i]);
	free(a);

	for(int i=0; i<dim; i++) free(array[i]);
	free(array);

	for(int i=0; i<dim; i++) free(c[i]);
	free(c);
	return 0;
}