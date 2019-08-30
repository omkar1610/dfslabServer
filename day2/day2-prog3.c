/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description:Suppose m and n are (signed) integers andxandyarefloating variables.  Write logical conditions that evaluate toTRUEif and only if:
					x+yis an integer.
					mlies strictly betweenxandy.
					mequals the integer part ofx.
					xis positive with integer part at least 3 andxandyarefloating with fractionalpart less than 0.3.
					mandnhave the same parity (i.e., are both odd or both even).
					mis a perfect square.
Acknowledgements:
------------------------------------*/
#include <math.h>

int isInt(float n) { return (int)n - n == 0?1:0; }
int intsquare(int n){ int tmp = sqrt(n); return tmp*tmp==n;}
int main()
{
	int m,n;
	float x,y;
	//scanf("%d%d%f%f",&m,&n,&x,&y);
	int flag = 1;
	if(!isInt(x+y)) flag =0;
	if(m<=x || m>=y) flag = 0;
	if(m != (int)x) flag = 0;
	if(!(x>0 && (int)x>2 &&(x - (int)x)<0.3)) flag = 0;

	if((m+n)%2 !=0) flag = 0;
	if(!intsquare(12)) flag = 0;
	printf("%d\n", flag);
	return 0;
}