#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	
	
	printf("FILE 1\n");
	FILE *fp = fopen(argv[1],"r");
	int c;
	do
	{
		fscanf(fp,"%d",&c);
		
		fgetc(fp);
		
		char *str; fscanf(fp,"%m[^\n]",&str);
		if(str[0] == 'r' || str[0] == 'w') printf("%d %s\n",c, str);
	}while(fgetc(fp) != EOF);

	fclose(fp);


	printf("\nFILE 2\n");
	fp = fopen(argv[2],"r");
	do
	{
		fscanf(fp,"%d",&c);
		
		fgetc(fp);
		
		char *str; fscanf(fp,"%m[^\n]",&str);
		if(str[0] == 'r' || str[0] == 'w') printf("%d %s\n",c, str);
	}while(fgetc(fp) != EOF);

	fclose(fp);



	return 0;
}