#include <stdio.h>
#include <stdlib.h>

#define getdata(x) ELEMENT[(x)].data
#define getnext(x) ELEMENT[(x)].next

#define TOT_ELE ll->tot_ele
#define NUM_ELE ll->num_ele
#define HEAD ll->head
#define TAIL ll->tail
#define FREE ll->free
#define ELEMENT ll->elements


#define DATA int
typedef struct
{
	DATA data;
	int next;
}NODE;

typedef struct
{
	int tot_ele, num_ele;
	int head, tail, free;
	NODE *elements;
}LL;

void init(LL *ll, int tot_ele)
{
	TOT_ELE = tot_ele;	NUM_ELE = 0;
	HEAD = TAIL = -1, FREE = 0;

	ELEMENT = malloc(TOT_ELE * sizeof(NODE));//calloc(TOT_ELE , sizeof(NODE));

	//Set link of free elements
	for(int i=0 ; i<TOT_ELE-1 ; i++)
		getnext(i) = i+1;
	getnext(TOT_ELE-1) = -1;
}

void showll(LL *ll)
{
	int head = HEAD;
	int num_ele = NUM_ELE;
	if(num_ele == 0)
		printf("EMPTY LIST\n");
	else
	{
		printf("LIST : ");
		while(num_ele--)
		{
			printf("%d ",ELEMENT[head].data);
			head = ELEMENT[head].next;
		}
		printf("\n");
	}
}

void showComplete(LL *ll)
{
	printf("\nDATA\n");
	for(int i=0, h = HEAD; i<NUM_ELE ; i++ , h = getnext(h))
			printf("%d %d\n",getdata(h), getnext(h));

	printf("FREE : ");
	for(int free = FREE; free != -1; free = getnext(free)) 
		printf("%d ",free);
	printf("\n");

	printf("\n");
}


void insert(LL *ll, DATA x)
{
	if(NUM_ELE == TOT_ELE -1)//Realloc before getting full
	{
		//realloc
		TOT_ELE *= 2;
		ELEMENT = realloc(ELEMENT, TOT_ELE * sizeof(NODE));
		
		//Join the free together
		for(int i=TOT_ELE/2 ; i<TOT_ELE ; i++)
			getnext(i) = i+1;
		getnext(TOT_ELE-1) = -1;
		//connect free's together
		getnext(FREE) = TOT_ELE/2;
		
	}
	if(NUM_ELE != 0)
	{
		NUM_ELE += 1;
		getdata(FREE) = x;
		
		TAIL = FREE;
		FREE = getnext(FREE);

	}
	else
	{
		NUM_ELE += 1;
		getdata(FREE) = x;

		HEAD = TAIL = FREE;
		FREE = getnext(FREE);
	}
}


int findPrev(LL *ll, DATA x) //won't search for root : To be used by delete function
{
	int num_ele = NUM_ELE-1;

	int head = HEAD;

	while(num_ele--)
	{
		int child = getnext(head);
		if(getdata(child) == x)
			return head;
		else
			head = child;
	}
	return -1;
}


void delete_data(LL *ll, DATA x)  
{
	//Remove head
	if(getdata(HEAD) == x)
	{
		if(NUM_ELE == 1)
		{
			getnext(HEAD) = FREE;
			FREE = HEAD;
			HEAD = TAIL = -1;
		}
		else
		{
			NUM_ELE--;

			int tmp = HEAD;
			HEAD = getnext(HEAD);
			getnext(tmp) = FREE;
			FREE = tmp;
		}
	}
	//Non Head
	else
	{
		int prev = findPrev(ll,x);
		if(prev != -1) 
		{
			NUM_ELE--;
			int curr = getnext(prev);
			if(curr == TAIL) TAIL = prev;
			getnext(prev) = getnext(curr);
			getnext(curr) = FREE;
			FREE = curr;
			// printf("deleted %d\n",getdata(curr));
		}
		// else 
		// printf("%d NOT PRESENT\n", x);
	}
}
