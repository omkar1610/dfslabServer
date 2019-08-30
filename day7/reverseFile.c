#include <stdio.h>


void revFile(char *name)
{
	FILE *fp,*fp2;
	fp = fopen(name,"r+");
	fp2 = fopen(name,"r+");
	fseek(fp2,-1,SEEK_END);
	
	char ch;
	while(ftell(fp) < ftell(fp2))
	{
		ch = fgetc(fp);
		fseek(fp,-1,SEEK_CUR);

		fputc(fgetc(fp2),fp);
		fseek(fp2,-1,SEEK_CUR);

		fputc(ch,fp2);
		fseek(fp2,-2,SEEK_CUR);
	}
	fclose(fp);fclose(fp2);
}

int main(int argc, char const *argv[])
{
	revFile("testfile");


	return 0;
}