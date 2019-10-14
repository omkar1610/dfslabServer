#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node* next;
}node;

void print(node* head)
{
	node* p = head;
	if(p == NULL) printf("EMP");
	else{
		while(p != NULL)
		{
			printf("%d,", p->data);
			p = p->next;
		}
	}
}


node* create(int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void insert_end(node **head, int x)
{
	node *new = create(x);
	if(*head == NULL) {
		*head = new;
	}
	else{
		node *p = *head;
		while(p->next) p = p->next;
		p->next = new;
	}
	//print(*head);printf("\n");
}

void insert_sorted(node **head, int x)
{
	node *new = create(x);
	node *p = *head;
	
	if(*head == NULL) {
		*head = new;
	}
	else if(p->data > x){
		new->next = p;
		*head = new;
	}
	else{
		while(p->next != NULL && p->next->data <x) p = p->next;
		new->next = p->next;
		p->next = new;
	}
	//print(*head);printf("\n");
}


void merge_sorted(node **head1, node **head2)
{
	node *p1 = *head1, *p2 = *head2, *tmp;
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data <= p2->data){
			node *tmp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p2 = p2->next;
		}
		else{

		}

	}
}


int main(int argc, char const *argv[])
{
	node *head_sort = NULL;
	int k;scanf("%d",&k);
	for(int i = 0;i<k;i++)
		insert_sorted(&head_sort, rand()%10000);
	
	print(head_sort);printf("\n");
	return 0;
}
