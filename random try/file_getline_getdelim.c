#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	int i, loc = 0;

	fp = fopen("trialtext", "r");
	if (fp == NULL)
	   exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) 
	{
		// printf("LINE : ~%s$\nTokens : \n", line);
		char *tmp;
		tmp = strtok(line, " \n");
		while(tmp != NULL)
		{
			printf("~%s$\n", tmp);
			tmp = strtok(NULL, " \n");
		}
	}
}