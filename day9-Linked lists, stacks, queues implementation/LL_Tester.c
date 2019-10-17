#include "LL_alternate.h"

int main()
{
	LL ll;
	init(&ll,5);
	showll(&ll); 
	insert(&ll, 3); 
	insert(&ll, 31);
	insert(&ll, 43);
	showll(&ll);

	delete_data(&ll, 3);
	delete_data(&ll, 13);

	showll(&ll);
		
}