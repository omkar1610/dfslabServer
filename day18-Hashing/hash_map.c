#include "map.h"

struct map_node {
  unsigned hash;
  void *value;
  map_node *next;
  /* char key[]; */
  /* char value[]; */
};


static unsigned map_hash(const char *str) {
  unsigned hash = 5381;
  // printf("hash for %s : ", str);
  while (*str) {
    hash = ((hash << 5) + hash) ^ *str++;
  }
  // printf("%u\n", hash);
  return hash;
}


static map_node *map_newnode(const char *key, void *value, int vsize) {
  map_node *node;

  int key_size = strlen(key) + 1;
  int value_offset = key_size + ((sizeof(void*) - key_size) % sizeof(void*));
  
  node = malloc(sizeof(*node) + value_offset + vsize);
 
  if (!node) return NULL;
 
  memcpy(node + 1, key, key_size);
  node->hash = map_hash(key);
  node->value = ((char*) (node + 1)) + value_offset;
  memcpy(node->value, value, vsize);
  return node;
}


static int map_bucketidx(map_base *m, unsigned hash) {
  /* If the implementation is changed to allow a non-power-of-2 bucket count,
   * the line below should be changed to use mod instead of AND */
  return hash & (m->nbuckets - 1);
}


static void map_addnode(map_base *m, map_node *node) {
  int n = map_bucketidx(m, node->hash);
  node->next = m->buckets[n];
  m->buckets[n] = node;
}


static int map_resize(map_base *m, int nbuckets) {
  map_node *nodes, *node, *next;
  map_node **buckets;
  int i; 
  /* Chain all nodes together */
  nodes = NULL;
  i = m->nbuckets;
  while (i--) {
    node = (m->buckets)[i];
    while (node) {
      next = node->next;
      node->next = nodes;
      nodes = node;
      node = next;
    }
  }
  /* Reset buckets */
  buckets = realloc(m->buckets, sizeof(*m->buckets) * nbuckets);
  if (buckets != NULL) {
    m->buckets = buckets;
    m->nbuckets = nbuckets;
  }
  if (m->buckets) {
    memset(m->buckets, 0, sizeof(*m->buckets) * m->nbuckets);
    /* Re-add nodes to buckets */
    node = nodes;
    while (node) {
      next = node->next;
      map_addnode(m, node);
      node = next;
    }
  }
  /* Return error code if realloc() failed */
  return (buckets == NULL) ? -1 : 0;
}


static map_node **map_getref(map_base *m, const char *key) {
  unsigned hash = map_hash(key);
  map_node **next;
  if (m->nbuckets > 0) {
    next = &m->buckets[map_bucketidx(m, hash)];
    while (*next) {
      if ((*next)->hash == hash && !strcmp((char*) (*next + 1), key)) {
        return next;
      }
      next = &(*next)->next;
    }
  }
  return NULL;
}


void map_deinit_(map_base *m) {
  map_node *next, *node;
  int i;
  i = m->nbuckets;
  while (i--) {
    node = m->buckets[i];
    while (node) {
      next = node->next;
      free(node);
      node = next;
    }
  }
  free(m->buckets);
}


void *map_get_(map_base *m, const char *key) {
  map_node **next = map_getref(m, key);
  return next ? (*next)->value : NULL;
}


int insert_(map_base *m, const char *key, void *value, int vsize) {
  int n, err;
  map_node **next, *node;
  /* Find & replace existing node */
  next = map_getref(m, key);
  if (next) {
    memcpy((*next)->value, value, vsize);
    return 0;
  }
  /* Add new node */
  node = map_newnode(key, value, vsize);
  if (node == NULL) goto fail;
  if (m->nnodes >= m->nbuckets) {
    n = (m->nbuckets > 0) ? (m->nbuckets << 1) : 1;
    err = map_resize(m, n);
    if (err) goto fail;
  }
  map_addnode(m, node);
  m->nnodes++;
  return 0;
  fail:
  if (node) free(node);
  return -1;
}


void map_remove_(map_base *m, const char *key) {
  map_node *node;
  map_node **next = map_getref(m, key);
  if (next) {
    node = *next;
    *next = (*next)->next;
    free(node);
    m->nnodes--;
  }
}


map_iter map_iter_(void) {
  map_iter iter;
  iter.bucketidx = -1;
  iter.node = NULL;
  return iter;
}


const char *map_next_(map_base *m, map_iter *iter) {
  if (iter->node) {
    iter->node = iter->node->next;
    if (iter->node == NULL) goto nextBucket;
  } else {
    nextBucket:
    do {
      if (++iter->bucketidx >= m->nbuckets) {
        return NULL;
      }
      iter->node = m->buckets[iter->bucketidx];
    } while (iter->node == NULL);
  }
  return (char*) (iter->node + 1);
}
