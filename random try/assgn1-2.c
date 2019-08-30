#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>
#define MAX(x,y) (((x)>(y))?(x):(y))

#define COPY_REALLOC {\
	copy(result,SIZE, ptr);\
	ptr = (int **)realloc(ptr, (1+maxpartloc)*sizeof(int *));\
	ptr[maxpartloc] = (int *)malloc((1+SIZE)*sizeof(int));\
}

int i; //iterator to be used in every function
int maxpartloc = 0;
int max_and = INT_MIN;

int compute_xor_and(int *result, int data[], int SIZE)
{
	int i, j, and = (1<<30)-1, xor = 0, mx = -1;
	
	for(i=1;i<=SIZE;i++)
		if(mx<result[i])
			mx = result[i];/// find max no of parttitons
	
	if(mx == 1) return INT_MIN; // I dont need single parttion, since at least 2 is needed.
	
	for(i=1;i<=mx;i++)
	{
		for(j=1;j<=SIZE;j++)
			if(result[j]==i)
				xor = xor^data[j];
		
		if(xor == 0) return 0;
		and = and & xor;
		xor = 0;
	}
	return and;
}

int printpart(int *result, int data[], int SIZE)
{
	int i, j, and = (1<<30)-1, xor = 0, mx = -1;
	
	for(i=1;i<=SIZE;i++)
		if(mx<result[i])
			mx = result[i];/// no of parttiton
	
	for(i=1;i<=mx;i++)
	{
		for(j=1;j<=SIZE;j++)
			if(result[j]==i)
				printf("%d",data[j]);
	if(i!=mx)printf("-1");
	}
}

void copy( int *result, int SIZE, int **ptr)
{

	int i;
	for(i=1;i<=SIZE;i++)
		ptr[maxpartloc][i] = result[i];
	maxpartloc++;
}	

//Recursive function to get the all the possible patitions
void part(int curr, int max,int *result, int data[], int SIZE, int **ptr)
{
	//Once we get a partition, compute the XOR and AND and store the max
	if(curr == SIZE)
	{
		result[curr] = max;
		int curr_and = compute_xor_and(result,data,SIZE);

		if(max_and < curr_and)
		{
			max_and = curr_and; maxpartloc = 0;
			//free(ptr);
			ptr = (int **)malloc((1+maxpartloc)*sizeof(int *));
			ptr[maxpartloc] = (int *)malloc((1+SIZE)*sizeof(int));
			copy(result,SIZE, ptr);
		}
		else if(max_and == curr_and)
		{
			copy(result,SIZE, ptr);
			ptr = (int **)realloc(ptr, (1+maxpartloc)*sizeof(int *));
			ptr[maxpartloc] = (int *)malloc((1+SIZE)*sizeof(int));
		}
	}

	else
	{
		int i;
		for(i=1;i<=max+1;i++)
		{
			result[curr+1] = i;
			if(curr+1 ==SIZE)
				part(curr+1,i,result,data,SIZE, ptr);
			else
				part(curr+1,MAX(max,i),result,data,SIZE, ptr);
		}
	}
}

int main()
{
	//All location calculations are staring from 1 not 0
	int SIZE = 2, tmp, i, j;
	char ch;
	int **ptr;
	//Initialising the array to take input
	int data[50];
	scanf("%d",&SIZE);
	for(i=1;i<=SIZE;i++) scanf("%d",&data[i]);
	//#############################################################################################################
	int *result = (int *)calloc((1+SIZE), sizeof(int)); //Here the artiotion value will be stored

	result[1] = 1;

	/*ptr = (int **)malloc(1*sizeof(int *));//2d array to store the max valued artiotions
	ptr[0] = (int *)malloc((1+SIZE)*sizeof(int));// putting 1 element first
	*/


	part(1,1,result, data, SIZE, ptr);
	

	
	for(i=0;i<maxpartloc;i++)
	{
		printpart(ptr[i],data,SIZE);
		printf("\n");
	}
	printf("%d\n", max_and);	
}