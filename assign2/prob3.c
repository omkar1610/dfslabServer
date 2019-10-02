#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int *list1, *list2, tmp; char ch;
	int len1, len2;
	int zeroflag1 = 0, zeroflag2 = 0;	// 1 => There is a zero in the list
										// 0 => All non-zero

	int neg1 = 0, neg2 = 0;		//-1 => The product is negative
								// 0 => The product is ositive

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
		if(zeroflag1 == 0 && tmp == 0) zeroflag1 = 1;
		if(tmp<0) neg1 = ~neg1;
		list1[i++] = tmp;
	}
	if(zeroflag1 == 0 && tmp == 0) zeroflag1 = 1;
	if(tmp<0) neg1 = ~neg1;
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
		if(zeroflag2 == 0 && tmp == 0) zeroflag2 = 1;
		if(tmp<0) neg2 = ~neg2;
		list2[i++] = tmp;
	}
	if(zeroflag2 == 0 && tmp == 0) zeroflag2 = 1;
	if(tmp<0) neg2 = ~neg2;
	list2[i++] = tmp;
	len2 = i;

	// for(i = 0 ; i<len1 ; i++) printf("%d ", list1[i]);printf("\n");
	// for(i = 0 ; i<len2 ; i++) printf("%d ", list2[i]);printf("\n");
	// printf("Zero %d %d Neg %d %d\n", zeroflag1, zeroflag2, neg1, neg2 );
	
																		// L1 	L2
	if(zeroflag1 && zeroflag2 && printf("L1 L2\n" )) goto exit; 		//  0	 0
	else if(zeroflag1 && neg2 && printf("L1\n")) goto exit; 			//  0 	-ve
	else if(zeroflag1 && !neg2 && printf("L2\n")) goto exit;			//  0 	+ve
	else if(neg1 && zeroflag2 && printf("L2\n" )) goto exit; 			// -ve 	 0
	else if(!neg1 && zeroflag2 && printf("L1\n" )) goto exit;			// +ve 	 0
	else if(neg1 && !neg2 && printf("L2\n" )) goto exit; 				// -ve 	+ve
	else if(!neg1 && neg2 && printf("L2\n" )) goto exit; 				// +ve  -ve
	else		//Both  all -ve or all +ve
	{

		//There is no zero in any list
		long double ratio = 1;
		for(i = 0, j = 0; i<len1 && j <len2; i++, j++) ratio = ratio * list1[i]/list2[j];
		
		while(i == len1 && j<len2)		ratio = ratio /list2[j++];
		while(j == len2 && i<len1)		ratio = ratio * list1[i++];

		printf("%Lf \n", ratio);
		printf("%s\n",ratio < 1?"L2":(ratio>1?"L1":"L1 L2") );
	}

	
	exit:
	free(list1); free(list2);

	return 0;
}