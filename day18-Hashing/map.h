
#ifndef MAP_H
#define MAP_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct map_node;

typedef struct map_node map_node;

typedef struct 
{
  map_node **buckets;//nodelist
  unsigned nbuckets, nnodes; //num_ele, tot_ele
} map_base;

typedef struct 
{
  unsigned bucketidx;
  map_node *node;
} map_iter;


#define map(T)\
  struct { map_base base; T *ref; T tmp; }


#define map_init(m)\
  memset(m, 0, sizeof(*(m)))


#define map_deinit(m)\
  map_deinit_(&(m)->base)


#define map_get(m, key)\
  ( (m)->ref = map_get_(&(m)->base, key) )


#define insert(m, key, value)\
  ( (m)->tmp = (value),\
    insert_(&(m)->base, key, &(m)->tmp, sizeof((m)->tmp)) )


#define map_remove(m, key)\
  map_remove_(&(m)->base, key)


#define map_iter(m)\
  map_iter_()


#define map_next(m, iter)\
  map_next_(&(m)->base, iter)


void map_deinit_(map_base *m);
void *map_get_(map_base *m, const char *key);
int insert_(map_base *m, const char *key, void *value, int vsize);
void map_remove_(map_base *m, const char *key);
map_iter map_iter_(void);
const char *map_next_(map_base *m, map_iter *iter);


typedef map(void*) map_void;
typedef map(char*) map_str;
typedef map(int) map_int;
typedef map(char) map_char;
typedef map(float) map_float;
typedef map(double) map_double;

#endif
