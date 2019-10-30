#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int isPrime(int n)
{
	if(n == 1) return 0;
	for (int i = 2; i*i<=n; ++i)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int firstDivisor(int *set_S, int size, int number)
{
	for (int i = 0; i < size; ++i)
	{
		if(set_S[i] != 0 && number%set_S[i]==0)
			return i;
	}
	return -1;
}

int secondDivisor(int *set_S, int start, int end, int value)
{
	for (int i = start; i < end; ++i)
	{
		if(set_S[i] == value)
			return i;
	}
	return -1;
}


int main()
{
	printf("Enter n and then n coefficients of the product poluynomial\n");
	int n; scanf("%d", &n);
	int product_poly[n];
	for (int i = 0; i < n; ++i) scanf("%d", &product_poly[i]);
	getchar();

	char *str; 
	int ele_S = 0, tot_S = 10;
	int *set_S = malloc(tot_S * sizeof(int));

	printf("Enter space seaprated list of the set S\n");
	scanf("%m[^\n]",&str);
	char *tmp = strtok(str, " ");


	do
	{
		if(isPrime(atoi(tmp)))
		{
			if(ele_S == tot_S -1)
			{
				tot_S *= 2;
				set_S = realloc(set_S, tot_S * sizeof(int));
			}
			set_S[ele_S++] =atoi(tmp);
		}
		tmp = strtok(NULL, " ");
	}while(tmp != NULL);

	for (int i = 0; i < n; ++i)
	{
		int number = product_poly[i];

		int first = firstDivisor(set_S, ele_S, number);
		if(first != -1)
		{
			int second = secondDivisor(set_S, first+1, ele_S, number/set_S[first]);
			if(second != -1)
				set_S[first] = set_S[second] = 0;

			else if(printf("False\n"))
				return 0;
		}
		else if(printf("False\n"))
			return 0;
	}

	printf("True\n");

}

// 3 4 5 7 11 10 13 2 1