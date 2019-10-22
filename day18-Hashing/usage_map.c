int *val = map_get(&m, "testkey");
if (val) {
  printf("value: %d\n", *val);
} else {
  printf("value not found\n");
}



Functions
All map functions are macro functions. The parameter m in each function should be a pointer to the map struct which the operation is to be performed on. The key parameter should always be a string value.

map_t(T)
Creates a map struct for containing values of type T.

/* Typedefs the struct `fp_map_t` as a container for type FILE* */
typedef map_t(FILE*) fp_map_t;

// map_init(m)
// Initialises the map, this must be called before the map can be used.

// map_deinit(m)
// Deinitialises the map, freeing the memory the map allocated during use; this should be called when were finished with a map.

// map_get(m, key)
// Returns a pointer to the value of the given key. If no mapping for the key exists then NULL will be returned.

// map_set(m, key, value)
// Sets the given key to the given value. Returns 0 on success, otherwise -1 is returned and the map remains unchanged.

// map_remove(m, key)
// Removes the mapping of the given key from the map. If the key does not exist in the map then the function has no effect.

map_iter(m)
Returns a map_iter_t which can be used with map_next() to iterate all the keys in the map.

// map_next(m, iter)
// Uses the map_iter_t returned by map_iter() to iterate all the keys in the map. map_next() returns a key with each call and returns NULL when there are no more keys.

// const char *key;
// map_iter_t iter = map_iter(&m);

// while ((key = map_next(&m, &iter))) {
//   printf("%s -> %d", key, *map_get(&m, key));
// }