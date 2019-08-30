/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:6 Aug 2019
Program description: Game of Stick picking
Acknowledgements:
------------------------------------*/
#include<stdio.h>

int play(int n, int flag)
{
	int r = n%4;
	if(r == 1)
	{
		//printf("\nI will Loose\n"); // for 4n+1 sticks impossible to win
		return -1;
	}
	else
	{
		//printf("\nWIN\n");	
		return r==0?3:r-1; // aim is to make 4n+1
	}
}



void show(int n, int pick, int flag)
{
	printf("%s picked %d sticks, Sticks left : %d\n",flag==0?"Comp":"You", pick, n );
}
int main(void)
{
	int n, flag ; //0 = comp, 1 = you

	printf("Enter the no of sticks and then who will play first(0-comp, 1-you)\n");
	scanf("%d%d",&n,&flag);
	int tmp;
	while(n>1)
	{
		if(flag == 1)
		{
			printf("\nYour Pick : ");
			scanf("%d",&tmp);
			n = n-tmp;
			printf("sticks left = %d\n", n);
			flag = 0;
			show(n, tmp, flag);
		}
		else
		{
			tmp = play(n, flag);
			if (tmp == -1) tmp = 2<n?2:n;
			n = n-tmp;
			printf("\nComp picked %d sticks; sticks left = %d\n", tmp, n);
			flag = 1;
		}
	}
	printf("%d Won!!!\n", !flag);

}