#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *s, **ptr;
	ptr = (char **)malloc(sizeof(char *));
	int tot = 0;

	while(scanf("%m[^\n]",&s)){
		//printf("Entered %s\n", s);
		ptr[tot] = (char *)malloc(strlen(s)*sizeof(char));
		strcpy(ptr[tot++], s);
		//printf("Copied %s\n", ptr[tot-1]);
		ptr = (char**)realloc(ptr,(tot+1)*sizeof(char *));
		free(s);
		getchar();
	}
	int i;
	for(i=0;i<tot;i++)
		printf("%s\n", ptr[i]);
}