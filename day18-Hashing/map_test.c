#include "map.h"


// typedef map(void*) map_void;
// typedef map(char*) map_str;
// typedef map(int) map_int;
// typedef map(char) map_char;
// typedef map(float) map_float;
// typedef map(double) map_double;


int main()
{
	map_void m;
	map_init(&m);


	insert(&m, "allright", "123");
	insert(&m, "omkar", "21");
	insert(&m, "bag", "98");
	insert(&m, "bag", "351");
	insert(&m, "newbag", "351");


	char *val = *map_get(&m, "omkar"); // map_get(m, key) = Returns a pointer to the value of the given key. If no mapping for the key exists then NULL will be returned.
	if (val)  printf("value: %s\n", val);
	else  printf("value not found\n");

	map_remove(&m, "omkar");

	const char *key;
	map_iter iter = map_iter(&m);

	while ((key = map_next(&m, &iter))) {
	  printf("%s -> %s\n", key, (char *)*map_get(&m, key));
	}



	map_deinit(&m);

}