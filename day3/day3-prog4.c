
 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:2 Aug 2019
Program description: Find thekthsmallest element inA∪Bwithout merging the two arrays.
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int main()
{
	int a[] = {2,3,4,5,6,8};
	int b[] = {0,1,2,5,7,9};//0 1 2 3 4 5 6 7 8 9
	int i = 0, j= 0, k;
	scanf("%d",&k);
	
	while(k--)
	{
		printf("%d %d %d %d\n",i,j, a[i], b[j] );
		if(a[i]>b[j])
			j++;
		else if(a[i]==b[j])
			i++,j++;
		else
			i++;
	}
	printf("%d\n", a[i-1]<b[j-1]?a[i-1]:b[j-1]);
}