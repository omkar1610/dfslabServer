#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	
	char *s1, *s2;
	s1 = argv[1];
	s2 = argv[2];
	int i,arr[27];
	printf("%s\n", argv[1]);
	printf("%s\n", s1);
	for(i=0;i<27;i++) arr[i] = 0;
	for(i=0;i<27;i++) printf("%d ",arr[i]); printf("\n");
	while(*s1) arr[*s1++ -'a']++;
	for(i=0;i<27;i++) printf("%d ",arr[i]); printf("\n");
	while(*s2) arr[*s1++ -'a']--;
	for(i=0;i<27;i++) printf("%d ",arr[i]); printf("\n");
	return 0;
}
