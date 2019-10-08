#include <stdio.h>
#include <stdlib.h>
long long int MOD=1000000007;
long long int mod(long long int n)
{

	return n<0?(n%MOD + MOD) % MOD:n%MOD;
}
int inversionPairs(int N, int K) {

	int tot = N*(N-1);
	if(K>(tot>>2)) K = (tot>>1)-K;
	long long int sum = 0;

    int i, j, k;
    
    long long int **data = malloc((1+N)*sizeof(long long int *));
    for(i = 1;i<=N;i++) data[i] = malloc(sizeof(long long int)*(1+(i*(i-1))/2));
    
    for(i = 1;i<=N;i++)
        data[i][0] = 1;


    for(i = 2; i<5 && i<=N;i++)
    {
    	int num = i*(i-1);
    	int num1 = ((i-1)*(i-2))>>1;
        for(j = 1; j<=num>>2 && j<=K;j++)
        {
        	data[i][j] = (data[i][j-1]+ (j>num1?0:data[i-1][j]))%MOD;
        }
        num = num>>1;
        for(; j<=num && j<=K ;j++)
        {
        	data[i][j] = data[i][num - j];
        }
    }
    for(i = 5; i<=N;i++)
    {
    	int num = i*(i-1);
    	int num1 = ((i-1)*(i-2))>>1;
        for(j = 1; j<=i-1 && j<=K;j++)
        {
        	data[i][j] = (data[i][j-1]+ (j>num1?0:data[i-1][j]))%MOD;
        }
        for(; j<=num>>2 && j<=K ;j++)
        {
        	data[i][j] = ((data[i][j-1] +(j>num1?0:data[i-1][j]))%MOD- data[i-1][j-i])%MOD;
        }
        num = num>>1;
        for(; j<=num && j<=K ;j++)
        {
        	data[i][j] = data[i][num - j];
        }
    }
    
 //    for(int p = 1; p<=N;p++)
	// {
	// 	printf("%d: ", p);
	// 	for(int q = 0; q<=((p*(p-1))/2) && q<=K;q++)
	// 		printf("%lld ", data[p][q]);
	// printf("\n");
 //    }
	    
	return data[N][K];
}

int rec(int n, int k)
{
	//printf("n k %d %d\n",n,k );
	if(k<0) return 0;
	else if(k==0) return 1;
	else if(k>(n*(n-1)/2)) return 0;
	else if(k<n)
	{
		int sum = 0;
		for(int i = 0;i<=k;i++)
			sum = mod(sum + rec(n-1,i));
		return sum;
	}
	else if(k>=n)
	{
		int sum = 0;
		for(int i = k-n+1;i<=k;i++)
			sum = mod(sum + rec(n-1,i));
		return sum;
	}
}

int main(int argc, char const *argv[])
{
	int n,k;scanf("%d%d",&n,&k);
	printf("%d\n",inversionPairs(n,k) );
	printf("%d\n",rec(n,k) );

}


// 1: 1 
// 2: 1 1 
// 3: 1 2 2 1 
// 4: 1 3 5 6 5 3 1 
// 5: 1 4 9 15 20 22 20 15 9 4 1 
// 6: 1 5 14 29 49 71 90 101 101 90 71 49 29 14 5 1 
