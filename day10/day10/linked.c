#include "linked_header.h"



int main()
{
	node *a = NULL, *b = NULL, *c = NULL, *d = NULL;

	char ch;
	int n;
	//while((scanf("%d%c",&n,&ch))==2 && ch == '\n')
	for(int i = 0;i<25;i++)
	{
		int k = rand()%4;
		0 == k?sorted_insert(&a,i):(1==k?sorted_insert(&b,i):(2==k?sorted_insert(&c,i):sorted_insert(&d,i)));
		//sorted_insert(&b,i);
	}
	printf("A list : "); show(a);
	printf("B list : ");show(b);
	printf("C list : "); show(c);
	printf("D list : ");show(d);
	node *new1 = NULL, *new2 = NULL, *new3 = NULL;
	merge(&a,&b,&new1);
	merge(&c,&d,&new2);
	merge(&new1,&new2,&new3);	
	printf("New list : ");show(new3);

}