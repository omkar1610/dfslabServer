#include <stdio.h>
#include <math.h>


int play(int m, int n)
{
	//Return 0 if any one of M and N is 0
	if(m==0 || n == 0) return 0;

	//If M or N is 1 then we will be using 1x1 boxes
	else if(m == 1 || n == 1)
		return m>n?m:n;


	else if(m<n)
	{
		//check if m is a proper power of 2 or not.
		int x = (int)log2(m);
		x = (int)pow(2,x);
		
		//If m is a proper power then put 1 box od MxM, then fill the rest
		if(m==x) return 1+play(m,n-x)+play(m-x,n); 

		//If m is not a proper power then break the whole area into 2 parts
		else return play(m-x,n)+play(x,n);
	}
	//similar things for m>=n
	else if(m>=n)
	{
		int x = (int)log2(n);
		x = (int)pow(2,x);
		if(n==x) return 1+play(m-x,n)+play(m,n-x);
		else return play(m,n-x)+play(m,x);
	}
}


int main()
{
	int m,n;scanf("%d%d",&m,&n);
	printf("%d",play(m,n));
}