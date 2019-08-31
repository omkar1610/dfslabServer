#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
	int a =1, b = 1;
	int k = 30;
	while(k--)
	{
		sleep(1);
		int c = a+b;
		printf("\r%d", c);
		a = b; b = c;
		fflush(stdout);
	}
	return 0;
}