#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *create(int x)
{
	NODE *tmp = malloc(sizeof(NODE));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void insert(NODE **node, int x)
{
	if(*node == NULL)
		*node =create(x);
	else
		insert(&((*node)->next), x);
}

void display(NODE *node)
{
	if(node != NULL)
	{
		printf("%d ", node->data);
		display(node->next);
	}
}
NODE *middle_part(NODE *node, NODE *mid)
{
	if(node->next == NULL)
		return node;
	if(node->next->next == NULL)
		return node;
	NODE *slow, *fast;
	slow = fast = node;
	while(fast != mid && fast->next != mid)
	{
	//	printf("%d \n", fast->data);
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("MID %d\n", slow->data);
	return slow;
}


NODE *middle(NODE *node)
{
	/*if(node == NULL)
		return NULL;*/
	if(node->next == NULL)
		return node;
	if(node->next->next == NULL)
		return node->next;

	NODE *slow, *fast;
	slow = fast = node;
	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("MID %d\n", slow->data);
	return slow;
}

void merge(NODE*, NODE* , NODE**, NODE*);

void mergeSort(NODE *node, NODE **result)
{
	//Base 1ele return simply
	NODE *mid = middle(node);
	mergeSort(node, result);
	mergeSort(mid, result);
	merge(node, mid, result, mid);
}

void merge(NODE *s1, NODE* m1, NODE **result, NODE *e1)
{
	if(s1 == e1 && m1 == NULL)
		return ;
	else if(s1 != e1 && m1 == NULL)
	{
		printf("HERE1 %d\n", s1->data);
		*result = create(s1->data);
		s1 = s1->next;
	}
	else if(s1 == e1 && m1 != NULL)
	{
		printf("HERE2 %d\n", m1->data);
		*result = create(m1->data);
		m1 = m1->next;
	}
	else //Both Not null
	{
		if(s1->data < m1->data)
		{
			printf("HERE3 %d\n", s1->data);
			*result = create(s1->data);
			s1 = s1->next;
		}
		else
		{
			printf("HERE4 %d\n", m1->data);
			*result = create(m1->data);
			m1 = m1->next;
		}
	}
	merge(s1, m1, &((*result)->next), e1);
}

void merge1(NODE *s1, NODE* m1, NODE *e1, NODE* e2, NODE *prev)
{
	//printf("Merge\n");
	//static NODE *prev = NULL;
	if(s1 == e1 && m1 == e2)
		return ;
	else if(s1 != e1 && m1 == e2)
	{
		//printf("HERE1 %d", s1->data);
		if(prev == NULL) prev = s1;
		else
		{
			prev->next = s1;
			prev = prev->next;
		}
		s1 = s1->next;
	}
	else if(s1 == e1 && m1 != e2)
	{
		//printf("HERE2 %d", m1->data);
		if(prev == NULL) prev = m1;
		else
		{
			prev->next = m1;
			prev = prev->next;
		}
		m1 = m1->next;
	}
	else //Both Not null
	{
		//printf("s1 %d m1 %d\n", s1->data, m1->data);
		if(s1->data < m1->data)
		{
			//printf("HERE3 %d", s1->data);
			if(prev == NULL) prev = s1;
			else
			{
				prev->next = s1; prev = prev->next;
			}
			s1 = s1->next;
		}
		else
		{
			printf("HERE4 %d", m1->data);
			if(prev == NULL) prev = m1;
			else
			{
				prev->next = m1; prev = prev->next;
			}
			m1 = m1->next;
		}
	}
 //	printf("\tPREV %d\n", prev->data);
	//if(s1 != e1)display(s1);printf("\n");
	merge1(s1, m1, e1, e2, prev);
}


void ms1(NODE *start, NODE *end, NODE *prev)
{
	//printf("MS %d %d %d %d\n", start->data, end->data, prev==NULL?-1:prev->data, middle_part(start, end)->data);
	if(start == NULL) return ;
	if(start->next == end ) {printf("One %d\n",start->data ); display(start); 
	printf("\n"); return; }

	NODE *mid = middle_part(start, end);

	NODE *tail = start; while(tail->next!=mid) tail = tail->next;

	ms1(start, mid, prev);
	ms1(mid, end, prev);
	merge1(start, mid, mid, end, NULL);
}


int main(int argc, char const *argv[])
{
	NODE *node, *result;
	NODE *prev = NULL;
	
	int a[] = {8,3,2,9,7,1,5,4}, i = 0;
	int n = sizeof(a)/sizeof(a[0]);
	node = create(a[i++]);
	while(i<n)
		insert(&node, a[i++]);  

	display(node); printf("\n");
	NODE *tail = node; while(tail->next) tail = tail->next;
	printf("MID = %d TAIL = %d\n", middle_part(node, NULL)->data, tail->data);

	NODE *mid = middle(node);
	
	//merge(node, mid, &result, mid);
	//merge1(node, mid, mid, tail, prev);
	ms1(node, NULL, prev);
	printf("\n");
	display(node);
	printf("\n");
	return 0;
}