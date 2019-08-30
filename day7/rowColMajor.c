#include <stdio.h>
#include <time.h>
int main()
{
	int n,flag;scanf("%d%d",&n,&flag);
	int a[n][n];
	int i=0, j;
	if(flag == 0){
	clock_t e = clock();
	for(;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]++;
	e = clock()-e;
	printf("%lf\n",(double)e/CLOCKS_PER_SEC );
	}
	else{
		i=0;
	clock_t s = clock();
	for(;i<n;i++)
		for(j=0;j<n;j++)
			a[j][i]++;
	s = clock()-s;
	printf("%lf\n",(double)s/CLOCKS_PER_SEC );
	}


}