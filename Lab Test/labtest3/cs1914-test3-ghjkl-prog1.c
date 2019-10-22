#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;scanf("%d",&n);
	char tmp;
	int i, b=0, w=0, r=0;
	char *str;

	getchar();
	scanf("%m[^\n]",&str);
	for(i=0;i<=strlen(str);i=i+2)
	{
		char tmp = str[i];
		if(tmp == 'W') 
			w++;
		else
			tmp == 'B'?b++:r++;
	}
	// printf("%d %d %d\n", b,w,r);
	int min = b;
	if(w<min) min = w;
	if(r<min) min = r;

	for (i = 0; i*i<=min; ++i) ; //checking nearest square number
	// printf("%d\n", i-1);
	int freq = i-1;
	for (int j = 0; j < freq; ++j)
	{
		for (i = 0; i < freq; ++i) printf("B ");
		for (i = 0; i < freq; ++i) printf("W ");
		for (i = 0; i < freq; ++i) printf("R ");
		printf("\n");
	}
	return 0;
}