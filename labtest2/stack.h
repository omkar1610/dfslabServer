#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	void *elements;
	size_t element_size;
	int num_elements, max_elements, spill_tol,operation_counter;
	void (*print_element)(void *, char flag);
	char flag;
} STACK;


void initStack (STACK *s, int element_size, int max_elements, int spill_tol, void (*print_element)(void *, char), char flag);

void freeStack(STACK *s);

void push(STACK *s, const void *eptr);

void pop(STACK *s);

void display(STACK *s);

void gen_display(STACK *s);

void spill_check(STACK *s);


//*******************DEFINITIONS****************************************



void initStack (STACK *s, int element_size, int max_elements, 
	int spill_tol, void (*print_element)(void *, char), char flag)
{
	s->element_size = element_size;
	s->num_elements = 0;
	s->max_elements = max_elements;
	s->spill_tol = spill_tol;
	s->operation_counter = 0;
	s->elements = malloc(s->max_elements * element_size);
	s->print_element = print_element;
	s->flag = flag;
}

void spill_check(STACK *s)
{
	if(s->operation_counter == s->spill_tol)
	{
		if(s->num_elements > 0) s->num_elements--; 
		s->operation_counter = 0;
	}
}

void push(STACK *s, const void *eptr)
{
	if(s->num_elements == s->max_elements)//OverFLow
	{
		s->operation_counter++;
		spill_check(s);
		return;
	}
	
	void* top = s->elements + s->num_elements * s->element_size;
	memmove(top, eptr, s->element_size);
	s->num_elements++;

	s->operation_counter++;

	spill_check(s);
}

void pop(STACK *s)
{
	if(s->num_elements == 0) //UnderFlow
	{
		s->operation_counter++;
		spill_check(s);
		return;// Underflow 
	}
	s->num_elements--;
	s->operation_counter++;


	spill_check(s);
}

void display(STACK *s)
{
	if(s->num_elements == 0) 
		printf("EMPTY STACK\n");
	else
	{	
		int tmp = s->num_elements-1;
		while(tmp>=0)
		{
			void* ele = s->elements + tmp * s->element_size;
			s->print_element(ele, s->flag);
			tmp--;
		}
		printf("\n");
	}


	s->operation_counter++;
	spill_check(s);
}


void gen_display(STACK *s) //Display Stack without Spill check
{
	if(s->num_elements == 0) 
		printf("EMPTY STACK\n");
	else
	{	
		int tmp = s->num_elements-1;
		while(tmp>=0)
		{
			void* ele = s->elements + tmp * s->element_size;
			s->print_element(ele, s->flag);
			tmp--;
		}
		printf("\n");
	}
}