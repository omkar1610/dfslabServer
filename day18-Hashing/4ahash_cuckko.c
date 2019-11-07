#include <stdio.h>
#include <stdlib.h>



void show(int **gpu, int n, int m)
{
	for (int i = 1; i <= n; ++i)
	{
		printf("GPU %d : ", i);
		for (int j = 0; j < m; ++j)
			if(gpu[i][j] == -1)
				printf(" ");
			else
				printf("%d ", gpu[i][j]);
		printf("\n");
	}
}



void hash(int **GPU, int x, int i, int n, int m, int *cycle)
{
	int hvalue = (x/i)%m;
	// printf("Hashing with %d in %dth pos %d\nCycle Array : ", x, i, hvalue);
	// for (int i = 0; i <m; ++i) 
	// 	printf("%d ", cycle[i]); 
	// printf("\n");
	
	
	if(GPU[i][hvalue] == -1)
		GPU[i][hvalue] = x;
	else
	{
		if(cycle[hvalue] != x)
		{
			int tmp = GPU[i][hvalue];
			GPU[i][hvalue] = x;

			cycle[hvalue] = tmp;
			// printf("cycle Recur :");
			// for (int i = 0; i <m; ++i) 
			// 	printf("%d ", cycle[i]); 
			// printf("\n");
			hash(GPU, tmp, (i%n)+1, n, m, cycle);
		}
		else
		printf("Collision\n");
	}
	// printf("cycle After :");
	// 		for (int i = 0; i <m; ++i) 
	// 			printf("%d ", cycle[i]); 
	// 		printf("\n");

	
}


int main()
{
	int n = 1, m = 10;
	scanf("%d%d",&n, &m);
	int *cycle = malloc((1+m) * sizeof(int));
	int **GPU = malloc((1+n)*sizeof(int*));
	for (int i = 1; i <= n; ++i)
	{
		GPU[i] = malloc(m * sizeof(int));
		for (int j = 0; j < m; ++j)
			GPU[i][j] = -1;
	}

	show(GPU, n, m);
	for (int i = 0; i < 20; ++i)
	{
		int tmp; scanf("%d", &tmp);
		hash(GPU, tmp, 1, n, m, cycle);
		show(GPU, n, m);
	}
}