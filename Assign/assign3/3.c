#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// FILE *fp = fopen("ip1","r");
	// int c;
	// do
	// {
	// 	fscanf(fp,"%d",&c);
	// 	printf("%d\n", c);
	// 	fgetc(fp);
	// 	char *str;
	// 	fscanf(fp,"%m[^\n]",&str);
	// 	printf("%s\n", str);
	// }while(fgetc(fp) != EOF);

	// fclose(fp);

	char *str;
	scanf("%m[^[2-5]\n]",&str);
	printf("%s\n", str);



	return 0;
}