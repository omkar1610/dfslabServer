#include <stdio.h>
#include <stdlib.h>

void prog(long double *list1, int len1, long double *list2, int len2)
{
	/*
		1. Just compute term wise ratio and keep on multiplying till the end and give out the result
	*/
	long double ratio = 1;
	int i, j;

	//Traverse through both till one list finishes and compute the ratio
	for(i = 0, j = 0; i<len1 && j <len2; i++, j++) 
		ratio = ratio * list1[i]/list2[j];
	
	//Both finished
	if(i == len1 && j == len2)
		printf("%s\n",ratio < 1?"L2":(ratio>1?"L1":"L1 L2") );

	//1st list finished
	else if(i == len1 && j != len2 && ratio<1)
	{
		//1st list finished and	 ratio<1 => So L2
		if(ratio<1)
			printf("%s\n","L2");	
		//1st list finished and ratio >1 => Go till ratio<1 or 1st finishing
		else
		{
			while(i == len1 && j<len2 && ratio>=1)		ratio = ratio /list2[j++];
			printf("%s\n",ratio < 1?"L2":(ratio>1?"L1":"L1 L2") );
		}
	}	
	// //2nd list finished
	else if(i != len1 && j == len2)
	{
		//2nd list finished and	 ratio>1 => So L1
		if(ratio>1)
			printf("%s\n","L1");
		//2nd list finished and ratio <1 => Go till ratio>1 or 2nd finishing
		else
		{
			while(j == len2 && i<len1 && ratio<=1)		ratio = ratio * list1[i++];
			printf("%s\n",ratio < 1?"L2":(ratio>1?"L1":"L1 L2") );
		}
	}
}


void prog2(long double *list1, int l1, long double *list2, int l2) // l1>=l2
{
	/*
	*	1.	Compute the element wise ratio of each term (L1/L2)
	*	2.	Store in 2 different list.
	*			i) ratio_gt => all the ratio > 1
	*			ii) ratio_lt => all the ratio <1
	*	3.	The aim is to finally keep all the ratio to be > 1(L1 is bigger) or < 1(L2 is bigger)
	*	4.	If both the list are empty, then equal lists
	*/


	long double ratio_gt[l1], ratio_lt[l1];
	int i, j, gt = 0, lt = 0;
	for(i=0; i<l2;i++) //Store term wise ratio in 2 groups , one gt 1 and other lt 1
	{
		long double ratio = list1[i]/list2[i];
		if(ratio>1)
			ratio_gt[gt++] = ratio;
		else if(ratio<1)
			ratio_lt[lt++] = ratio;
	}
	//copy rest of list1 to ratio gt list
	for(i=l2;i<l1;i++)
		ratio_gt[gt++] = list1[i];

	//Club one ratio gt 1 and one ratio lt 1, to avoid underflow
	while(gt != 0 && lt != 0) // Go till one list vanishes
	{
		long double ratio = ratio_gt[gt-1] * ratio_lt[lt-1];
		if(ratio>1) // Store in gt 
			ratio_gt[gt-1] = ratio, lt--;
		else if(ratio<1)
			ratio_lt[lt-1] = ratio, gt--;
		else if(ratio == 1)
			lt--, gt--;
	}
	if(gt == 0 && lt == 0)
		printf("L1 L2\n");
	else if(gt == 0)
		printf("L2\n");
	else if(lt == 0)
		printf("L1\n");
	
}

int main()
{
	long double *list1, *list2, tmp; char ch;
	int len1, len2;
	int max_loc = 5, i = 0, j = 0;

	//################################################
	//			Input for List 1					//
	//################################################
	list1 = malloc(max_loc*sizeof(long double));
	while(scanf("%Lf%c",&tmp, &ch)==2 && ch !='\n')
	{
		if(i == max_loc-2)
		{
			max_loc *= 2;
			list1 = realloc(list1, max_loc * sizeof(long double));
		}
		list1[i++] = tmp;
	}
	list1[i++] = tmp;
	len1 = i;


	//################################################
	//			Input for List 2					//
	//################################################
	
	max_loc = 5; i = 0;
	list2 = malloc(max_loc*sizeof(long double));
	while(scanf("%Lf%c",&tmp, &ch)==2 && ch !='\n')
	{
		if(i == max_loc-1)
		{
			max_loc *= 2;
			list2 = realloc(list2, max_loc * sizeof(long double));
		}
		list2[i++] = tmp;
	}
	list2[i++] = tmp;
	len2 = i;

	

	prog(list1, len1, list2, len2);



	if(len1>=len2)
		prog2(list1, len1, list2, len2); // l1>=l2
	else
		prog2(list2, len2, list1, len1);


	
	
	free(list1); free(list2);

	return 0;
}