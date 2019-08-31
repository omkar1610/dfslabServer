 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: chess
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<math.h>

int chess(int m, int n, int i, int j,int k)
{
	if(i<0 || j<0 || i>=m || j>=n)
		return 0;
	if(k==0)
		return 1;
	else
	{
		return chess(m,n,i+2,j+1,k-1)+
		chess(m,n,i+2,j-1,k-1)+
		chess(m,n,i-2,j+1,k-1)+
		chess(m,n,i-2,j+1,k-1)+
		chess(m,n,i+1,j+2,k-1)+
		chess(m,n,i-1,j+2,k-1)+
		chess(m,n,i+1,j-2,k-1)+
		chess(m,n,i-1,j-2,k-1);
	}
}
int main()
{	
	int m,n,i,j,k;
	scanf("%d%d%d%d%d",&m,&n,&i,&j,&k);
	float prob = (float)chess(m,n,i,j,k)/(float)pow(8,k);
	printf("%f\n", prob);
	return 0;
}