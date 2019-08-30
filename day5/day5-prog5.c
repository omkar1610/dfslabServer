 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: iitkgp
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int populate(int **A)
{
	int i, n; scanf("%d",&n);
	if(n>20 || n<1) {printf("INVALID ENTRY\n");return -1;	}
	*A = (int *)malloc(n*sizeof(n));

	for(i=0;i<n;i++)
		printf("A[%d] = ", i), scanf("%d",(*A)+i);
	return n;
}


void show(int *A, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ", A[i]);
}

int bitsum(int *A, int n, int num)
{
	int sum = 0, i;
	for(i = n-1 ;i>=0;i--)
		if(num & 1<<i)
			sum += A[i];
	return sum;
}

void sum_check(int *A, int n, int sum)
{
	int i,range = 1<<n;
	for(i = 1; i<range;i++)
	{
		//printf("\nS%d", bitsum(A,n,i));
		if(sum == bitsum(A,n,i))
		{
			printf("GOT SOME FOR %d\n", i);
			break;
		}
	}
	if(i==range) printf("NOT FOUND\n");
}


int main()
{
	int *A, i;
	int n = populate(&A);
	printf("%d\n", n);


	for(i=0;i<n;i++)
		printf("%d ", *(A+i));
	printf("\n");
	show(A,n);
	//printf("\n%d\n ", bitsum(A,4,8));
	sum_check(A,n,10);



}