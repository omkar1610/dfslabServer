
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Malloc(n,type) (type *)malloc((unsigned) ((n)*sizeof(type)))
int main()
{

	//n = no of elements, flag is recognize negative elements
	int i=0, j, tmp, n = 1, *data,sum=0,mx=INT_MIN;
	int length = INT_MAX, loc=0,start = 0;
	

	char ch;
	data = (int *)malloc(n*sizeof(int));
	while(scanf("%d%c",&tmp,&ch) == 2 && ch ==' ') // keep on taking inut till end of line
	{
		data[n-1] = tmp; n++;
		data = (int *)realloc(data, n*sizeof(int));// keep on allocating extra one space for each input
		
	}
	data[n-1] = tmp;
	
	//Finding maxsum possible using Kadane's Algorithm
	for(i=0;i<n;i++)
	{
		sum += data[i];
		if(sum>mx) mx = sum;
		if(sum<0) sum = 0;
	}

	sum = 0;

	//If max is non-positive then no positive integer exist, so just find the max value and keep on printing
	if(mx<=0)
	{
		for(i=0;i<n;i++)
			if(data[i] == mx)
				printf("%d %d\n", i,i);	
		printf("%d\n",mx);
	}
	//If max is positive do another pass to get min length
	else
	{
		for(i=0;i<n;i++)
		{
			sum += data[i];
			//If we get the max we check for  lwngth of the sunsequence 
			if(sum == mx)
			{
				if(length>i-start+1) //If we get a less length sequence then, we start storing this one anf drop all the index stored till now
				{
					loc = 0;// dropping all the numbers stored till now
					data[loc++] = start; //storing the starting point of the seq
					length = i - start +1; //new length
					start = i+1;
					sum = 0;				//reset sum to find a new seq
				}
				else if(length == i-start+1) //if equal length then, add the starting point with already existing list of starting index
				{
					data[loc++] = start;
					start = i+1;
					sum = 0;
				}
			}
			else if(sum<=0) // if we get non positive sum we simply reset the sum and starting index for current seq
				sum = 0, start = i+1;
		}
		//print the start and end indices of all the otimal strings
		for(i=0;i<loc;i++)
			printf("%d %d\n", data[i],data[i] + length-1);
		printf("%d", mx); //print max value
	}
	
	return 0;
}