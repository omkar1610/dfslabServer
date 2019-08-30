#include <stdio.h>



int isPrime(int n)
{
	if(n==1) return 0;
	else if(n==2) return 1;
	else{
		int i, sqr = n*n;
		for(i = 2;i*i < sqr; i++)
			if(n%i == 0)
				return 0;
		}
	return 1;
}

//wilsons thorem (n-1)! cong -1 (mod n)

int main(int argc, char const *argv[])
{
	int n = 30;
	int i,fact = 1;
	for(i=2;i<n;i++)
	{
		fact = fact * (i-1);
		if((fact+1)%i ==0)
			printf("%d %d\n",i, fact*i);
	}
	return 0;
}
