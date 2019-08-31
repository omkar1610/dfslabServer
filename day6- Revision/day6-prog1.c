#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct strng{
	char line[200];
	int *arr = (int *)calloc(26, sizeof(int));
};


void str_to_array(char string[], int *array)
{
	int i;
	for(i=0;i<strlen(string);i++)
		if(string[i]!=' ')
			array[string[i] - 'a']++;
}


int main()
{
	struct strng data[100];
	int n;
	scanf("%d",&n);
	int i, j;
	for(i=0;i<=n;i++)
		{
			fgets(data[i].line, 200, stdin);
			str_to_array(data[i].line, data[i].arr);
		}

	for(i=0;i<=n-1;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				
			}
		}
}