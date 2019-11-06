#include "BTree.h"

typedef struct{
	int data;
}DATA;

void dataPrint(void *data)
{
	printf("%d ",*(int*)(data) );
}



int main()
{
	int n; scanf("%d", &n);
	BTREE **ptr = malloc(n*sizeof(BTREE*)); //Array of pointers to btree;

	DATA d;
	for(int i = 0; i<n ;i++)
	{
		ptr[i] = malloc(sizeof(BTREE));
		initTree(ptr[i], sizeof(DATA), dataPrint);
		
		int row;scanf("%d",&row);
		for(int j=0;j<row;j++)
		{
			int x, l, r;
			scanf("%d%d%d", &x, &l, &r);
			d.data = x;
			insert(ptr[i], &d, l, r);
		}

	}
	inorder(ptr[1], 0);
	printf("%d\n", update_height(ptr[1], 0));

	return 0;
}