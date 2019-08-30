#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE *fp, *fp2;
	fp = fopen("polyfile","r");
	fp2 = fopen("polyfile","r");
	char *line = NULL, *line2 = NULL;
	size_t read, read2;
	size_t len = 0, len2 = 0;
	int i;

	read = getline(&line, &len, fp);
	int poly1 = atoi(line); i = poly1+1;

	while(i--) getline(&line2, &len2, fp2);
	
	read2 = getline(&line2, &len2, fp2);

	int poly2 = atoi(line2);

	printf("%d %d\n", poly1,poly2);

	int result[50], res = 0, c1,c2,ex1,ex2;;
	
	getline(&line, &len, fp);
	getline(&line2, &len2, fp2);
	
	c1 = atoi(strtok(line," "));
	line += strlen(strtok(line," ")) + 1;
	ex1 = atoi(strtok(line," "));

	c2 = atoi(strtok(line2," "));
	line2 += strlen(strtok(line2," ")) + 1;
	ex2 = atoi(strtok(line2," "));

	while(poly1 && poly2)
	{
		printf("POLY %d %d\n", poly1, poly2);

		printf("%d %d and %d %d \n", c1, ex1, c2, ex2);

		if(ex1>ex2)
		{
			printf("1\n");
			result[res++] = c1;result[res++] = ex1;
			getline(&line, &len, fp);
			c1 = atoi(strtok(line," "));
			line += strlen(strtok(line," ")) + 1;
			ex1 = atoi(strtok(line," "));
			poly1--;
		}
		else if(ex1<ex2)
		{
			printf("2\n");
			result[res++] = c2;result[res++] = ex2;
			getline(&line2, &len2, fp2);
			c2 = atoi(strtok(line2," "));
			line2 += strlen(strtok(line2," ")) + 1;
			ex2 = atoi(strtok(line2," "));
			poly2--;
		}
		else if(ex1 == ex2)
		{
			printf("3\n");
			result[res++] = c1+c2;result[res++] = ex1;
			
			getline(&line, &len, fp);
			getline(&line2, &len2, fp2);
			c1 = atoi(strtok(line," "));
			line += strlen(strtok(line," ")) + 1;
			ex1 = atoi(strtok(line," "));

			c2 = atoi(strtok(line2," "));
			line2 += strlen(strtok(line2," ")) + 1;
			ex2 = atoi(strtok(line2," "));
			poly1--;poly2--;
		}		
		for(i=0;i<res;i++)
			printf("%d ", result[i]);printf("\n");
	}
	

	fclose(fp);fclose(fp2);
}