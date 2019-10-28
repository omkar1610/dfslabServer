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


int main()
{
	int n; scanf("%d", &n);
	int data[n];
	for (int i = 0; i < n; ++i) scanf("%d", &data[i]);

	char *str; int count = 0;
	getchar();

	scanf("%m[^\n]",&str);
	for (int i = 0; i < strlen(str); ++i) if(str[i] == ' ') count++;


	int *coeff = malloc(count * sizeof(int));

	int i = 0, tmp = atoi(strtok(str," "));

	if(isPrime(tmp))coeff[i++] = tmp;
	

	while(i < count-1)
	{
		tmp = atoi(strtok(NULL, " "));
		printf("%d ", tmp);
		if(isPrime(tmp)) coeff[i++] = tmp;
	}






	for (int i = 0; i < count; ++i)
	{
		printf("%d ", coeff[i]);
	}
}