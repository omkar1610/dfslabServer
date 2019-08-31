#include <stdio.h>
#define inf 999999
#define SIZE 4
int main()
{
	int adj[SIZE][SIZE] = {0,1,0,0,
						1,0,1,1,
						0,1,0,0,
						0,1,0,0};
	int path[SIZE][SIZE];
	int i, j, k;
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			path[i][j] = (i==j)?0:((adj[i][j]==1)?adj[i][j]:inf);


	for(k=0;k<2;k++){

		for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
				if(path[i][j] > path[i][k] + path[k][j]) 
					path[i][j] = path[i][k] + path[k][j];
			}
		}
		/*for(i=0;i<SIZE;i++){
		*	for(j=0;j<SIZE;j++)
		*		printf("%d\t",path[i][j]);
		*	printf("\n");
		*	}
		*
		*printf("\n");
		*/
	}


	for(i=0;i<SIZE;i++){
			printf("Reachable from Node %d : ",i+1);
			for(j=0;j<SIZE;j++){
				if(path[i][j]!=inf) printf("%d ", j+1);
			}
			printf("\n");
		}

}


