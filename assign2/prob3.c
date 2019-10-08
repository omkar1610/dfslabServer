#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int *list1, *list2, tmp; char ch;
	int len1, len2;
	int max_loc = 5, i = 0, j = 0;

	//Input for List 1
	
	list1 = malloc(max_loc*sizeof(int));
	while(scanf("%d%c",&tmp, &ch)==2 && ch !='\n')
	{
		if(i == max_loc-2)
		{
			max_loc *= 2;
			list1 = realloc(list1, max_loc * sizeof(int));
		}
		list1[i++] = tmp;
	}
	list1[i++] = tmp;
	len1 = i;


	//Input for List 2
	
	max_loc = 5; i = 0;
	list2 = malloc(max_loc*sizeof(int));
	while(scanf("%d%c",&tmp, &ch)==2 && ch !='\n')
	{
		if(i == max_loc-1)
		{
			max_loc *= 2;
			list2 = realloc(list2, max_loc * sizeof(int));
		}
		list2[i++] = tmp;
	}
	list2[i++] = tmp;
	len2 = i;

	long double ratio = 1;
	//Traverse through both till one list finishes and compute the ratio
	for(i = 0, j = 0; i<len1 && j <len2; i++, j++) ratio = ratio * list1[i]/list2[j];
	
	//Both finished
		
	//2nd list finished and	 ratio>1 => So L1

	//2nd list finished and ratio <1 => Go till ratio>1 or 2nd finishing

	//1st list finished and	 ratio<1 => So L2

	//1st list finished and ratio >1 => Go till ratio<1 or 1st finishing


	while(i == len1 && j<len2 && ratio>=1)		ratio = ratio /list2[j++];
	while(j == len2 && i<len1 && ratio<=1)		ratio = ratio * list1[i++];

	printf("%Lf \n", ratio);
	printf("%s\n",ratio < 1?"L2":(ratio>1?"L1":"L1 L2") );

	
	exit:
	free(list1); free(list2);

	return 0;
}