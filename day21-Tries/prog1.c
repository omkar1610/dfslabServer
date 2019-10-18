#include "common.h"
#include "trie.h"


void func(char *str, int n)
{
	if(strlen(str)<n)
		return;
	else
	{
		for(int i=0 ; i<strlen(str) - n + 1 ; i++)
			insert_string(str+i);
	}
}

void prog1()
{
	int n; scanf("%d", &n);
	char *str;
	printf("Put $ to end the input\n");

	scanf("%m[^$]",&str);
	fflush(stdin);

	char *tmp = strtok(str, " \n");
	func(tmp,n);
	while(tmp != NULL)
	{
		// printf("%s\n", tmp);
		func(tmp, n);
		tmp = strtok(NULL, " \n");
	}
}

int main()
{
	init_trie();
	// insert_string("app");
	// insert_string("an");
	// insert_string("an");
	// insert_string("apple");
	// insert_string("hello");
	// insert_string("1234");
	// insert_string("52");
	// insert_string("124");
	// insert_string("12");
	// show();
	// trie_dfs();
	// printf("%d\n", trie_search("124"));	
	prog1();
	trie_dfs();
}