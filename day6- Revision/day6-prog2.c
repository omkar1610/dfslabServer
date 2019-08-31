#include <stdio.h>
#include <string.h>

void strcp(char *s1, char *s2, int n)
{
	while(n--)
		*s2++ = *s1++;
}

int exist_from_start(char *str, char *patt, int start, int length)
{
	int i;
	for(i=start;i<start+length;i++)
		if(*(str+i) != *(patt+i))
			return 0;
	return 1;
}


int chk_perio(char *str, char *patt, int pattlength)
{
	int i;
	for(i=0;i<strlen(str);i += pattlength)
}

int main()
{
	char str[] = "abcadabcad";
	int i;
	printf("%lu\n",strlen(str) );
	char tmp[200];
	for(i=1;i<=strlen(str);i++)
	{
		strcp(str,tmp,i);
		printf("%s\n", tmp);
	}

}