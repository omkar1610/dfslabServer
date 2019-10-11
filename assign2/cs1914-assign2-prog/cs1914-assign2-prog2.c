#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

int last_same(char *a, char *b)// Simply returns how many bits are same from last
{
	int i, j, count = 0;
	for(i = strlen(a), j = strlen(b); i>=0 && j>=0 && a[i]==b[j]; i--, j--, count++) ;

	return count-1;
}

int first_same(char *a, char *b)// Simply returns how many bits are same from first
{
	int i;
	for(i = 0; i<strlen(a) && i<strlen(b) && a[i]==b[i]; i++) ;

	return i;
}

void prog(char *a, char *b, char *n1, char *n2, float prob)
{
	int i = 0, j = 0;
	size_t la = strlen(a), lb = strlen(b), ln1 = strlen(n1), ln2 = strlen(n2);
	// printf("%lu %lu %lu %lu\n", la,lb,ln1,ln2);

	//If sum of parent and child length are not same or no probability of cross over
	if(la+lb != ln1+ln2 || prob == 0)
	{
		printf("INFEASIBLE\n");
		return;
	}
	//Any one child is null, just check both parrents concatenation
	else if(ln1 == 0)
	{
		int f2 = first_same(b,n2), l1 = last_same(a,n2);
		if(f2 == lb && l1 == la)
			printf("0 %lu\n", lb);
	}
	else if(ln2 == 0)
	{
		int f1 = first_same(a,n1), l2 = last_same(b,n1);
		if(f1 == la && l2 == lb)
			printf("%lu 0\n", la);
	}
	//This just checks cross over points and returns any one if multile answers are possible
	else
	{

		int f1 = first_same(a,n1), f2 = first_same(b,n2);
		int l1 = last_same(a,n2), l2 = last_same(b,n1);

		if(f1+l1-la == f2+l2-lb) 
			printf("%d %d\n", f1, f2);

		else// if(f1+l1 < la || f2+l2 <lb) 
			printf("INFEASIBLE\n");
	}
}

int main()
{
	char *a,*b,*n1,*n2;
	float prob;
	scanf("%f",&prob);getchar();

	scanf("%m[^\n]", &a);getchar();if(a == NULL) a = "";
	scanf("%m[^\n]", &b);getchar();if(b == NULL) b = "";
	scanf("%m[^\n]", &n1);getchar();if(n1 == NULL) n1 = "";
	scanf("%m[^\n]", &n2);getchar();if(n2 == NULL) n2 = "";

	prog(a,b,n1,n2, prob);

	return 0;
}