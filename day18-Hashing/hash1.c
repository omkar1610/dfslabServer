#include "cuckko.h"
#include <math.h>

int h1(int k)
{
	return k%8;
}

int h2(int k)
{
	return (int)(ceil(log(k)/log(10)));
}


int main()
{
	int tot_ele = 8;
	CUCKOO box;
	init(&box, tot_ele, h1, h2);
	
	showTable(&box);

	insert(&box, 10); 
	insert(&box, 1); 
	insert(&box, 92); 
	insert(&box, 4); 
	insert(&box, 2); 
	showTable(&box);
}