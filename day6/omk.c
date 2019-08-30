#include<stdio.h>
#include<math.h>


int main(){
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int last = (sqrt(8*n+1)-1)/2;
		printf("LAST %d\n",last);
		int remain = n - (last*(last+1)/2);
		printf("REMAIN %d\n",remain);
		if(remain == 0){
			int sum = last+1;
			if(last%2==0){
				printf("SUM %d ANS %d", sum, sum-1);
			}
			else{
				printf("SUM %d ANS %d", sum, 1);
			}
		}
		else{
			int i,sum = last +2;
			if(last%2!=0){
				printf("SUM %d ANS %d", sum, remain);				
			}
			else{
				printf("SUM %d ANS %d", sum, sum - remain);
			}
		}
	}
	
}
