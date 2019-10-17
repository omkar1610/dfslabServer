#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int t1, t2;
}NODE;


typedef struct
{
	NODE *table;
	int tot_ele;
	int (*h1)(int k);
	int (*h2)(int k);
}CUCKOO;


void init(CUCKOO *box, int tot_ele, int (*h1)(int k), int (*h2)(int k))
{
	box->tot_ele = tot_ele;
	box->h1 = h1;
	box->h2 = h2;
	box->table = malloc(tot_ele*sizeof(NODE));
	for(int i=0 ; i<box->tot_ele ; i++)
		box->table[i].t1 = box->table[i].t2 = -1;
	#ifdef DEBUG
		printf("Initialised\n");
	#endif
}


void showTable(CUCKOO *box)
{
	for(int i=0 ; i<box->tot_ele ; i++)
		printf("%d = %d %d\n", i, box->table[i].t1, box->table[i].t2);
	printf("\n");
}



void ins_h2(CUCKOO *box, int k);

void insert(CUCKOO *box, int k)//H1
{
	#ifdef DEBUG
		printf("with h1 to t1 %d\n",k);
	#endif
	int tmp = box->h1(k);
	if(box->table[tmp].t1 == -1)
		box->table[tmp].t1 = k;
	else
	{
		int k_ = box->table[tmp].t1;
		box->table[tmp].t1 = k;
		ins_h2(box, k_);
	}
}

void ins_h2(CUCKOO *box, int k)
{
	#ifdef DEBUG
		printf("with h2 to t2 %d\n",k);
	#endif
	int tmp = box->h2(k);
	if(box->table[tmp].t2 == -1)
		box->table[tmp].t2 = k;
	else
	{
		int k_ = box->table[tmp].t2;
		box->table[tmp].t2 = k;
		insert(box, k_);
	}
}
