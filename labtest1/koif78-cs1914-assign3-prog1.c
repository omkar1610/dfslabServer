#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Func to check if the character is in a-z or A-Z or not
int isAlpha(char c)
{
	if((c<='z' && c>='a') || (c<='Z' && c>='A'))
		return 1;
	return 0;
}



int main()
{	
	char *s;
	int tot = 0, i, length, max_length = -1, loc=0;

	int *arr = (int *)malloc(sizeof(int)); //Array to store length of each word 
											//this will help in finding the frequency later

	//Keep on getting till we get a new line
	while(scanf("%m[^\n]",&s))
	{
		length = 0, i =0;
		//till the endof this string we do some processing
		while(s[i] != '\0')
		{
			if(isAlpha(s[i])) length++; //If i get alphabet, then i have to keep track of the length of the word
			else {
				if(length>0) //only for positive length i will save the length
				{
					if(max_length < length) max_length = length;
					arr[loc++] = length;
					arr = (int *)realloc(arr, (1+loc)*sizeof(int)); //dynamically allocate a new location for the next length if required
				}
				length = 0;//reset the length
			}
			i++;
		}
		free(s);//%m requires this to be freed
		getchar();//to go past the \n received
	}

	//if the input ends with a valid word, that has to be added here
	if(length>0)
	{
		if(max_length<length) max_length = length;//update max length for frequency as well
		arr[loc++] = length;
	}


	//in result, result[i] = frequency of i length word, else 0
	int *result = (int *)calloc((1+max_length), sizeof(int));

	//save freq of each length word;
	for(i=0;i<loc;i++) result[arr[i]]++;
	
	int max_freq = 0;

	//Find max freq once i have the lengths
	for(i=0;i<=max_length;i++)
		if(result[max_freq]<result[i])
			max_freq = i;

	printf("\n%d %d\n",max_freq, result[max_freq] );
}