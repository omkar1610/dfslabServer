#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XXX {\
for(int i = 0; i<s->num_elements;i++)\
		printf("%d ", (((int *)(s->elements))[i]));\
	printf("\n");\
}


#ifndef _GSEQUENCE_
#define _GSEQUENCE_

typedef int bool;

typedef struct {
	void *elements;
	size_t element_size, num_elements, max_elements;
} SEQUENCE;


void initSEQUENCE (SEQUENCE *s, int element_size);

void freeSEQUENCE(SEQUENCE *s);

bool isEmpty(const SEQUENCE *s);

void insert(SEQUENCE *s, const void *eptr);

void pop(SEQUENCE *s, void *eptr);

size_t LENGTH(SEQUENCE *s);
#endif	//_GSEQUENCE_


size_t LENGTH(SEQUENCE *s)
{
	return s->num_elements;
}

void initSEQUENCE (SEQUENCE *s, int element_size)
{
	s->element_size = element_size;
	s->num_elements = 0;
	s->max_elements = 50;
	s->elements = malloc(s->max_elements * element_size);
}

void insert(SEQUENCE *s, const void *eptr)
{
	void* top = s->elements + s->num_elements * s->element_size;
	memmove(top, eptr, s->element_size);
	s->num_elements++;
}



int main(int argc, char const *argv[])
{
	SEQUENCE st;
	SEQUENCE *s = &st;
	initSEQUENCE(s, sizeof(int));
	int x = 5; int *a = &x;

	printf("Total elements : %lu\n", LENGTH(s));
	insert(s,a);
	x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);
	x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);x++;insert(s,a);
	printf("Total elements : %lu\n", LENGTH(s));
	XXX



	return 0;
}