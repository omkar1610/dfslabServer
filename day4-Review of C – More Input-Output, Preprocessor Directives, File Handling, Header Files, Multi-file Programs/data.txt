/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:6 Aug 2019
Program description: Macro define
Acknowledgements:
------------------------------------*/
#include<stdio.h>

#define IMPLY(x, y) ( !(x) || (y))
#define SWAP(x, y) {\
	(x) = (x) + (y);\
	(y) = (x) - (y);\
	(x) = (x) - (y);\
}

#define MIN(x, y) ((x)<(y))?(x):(y)
#define MAX(x, y) ((x)>(y))?(x):(y)

#define INF_PRINT(x) while(1) printf(x"\n");
#define LSB(x) ((x) || 1)


int main(int argc, char const *argv[])
{
	printf("%d\n", IMPLY(1+2, 3>2));
	int a = 5, b = 2;
	SWAP(a, b);
	printf("%d %d\n", a,b);
	printf("%d\n", MIN(1,2-5));
	printf("%d\n", MAX(a, b));
	printf("%d\n", LSB(a));
	//INF_PRINT("fsadas")
	return 0;
}