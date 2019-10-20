#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"


// typedef struct UT_hash_handle {
//    struct UT_hash_table *tbl;
//    void *prev;                       /* prev element in app order      */
//    void *next;                       /* next element in app order      */
//    struct UT_hash_handle *hh_prev;   /* previous hh in bucket order    */
//    struct UT_hash_handle *hh_next;   /* next hh in bucket order        */
//    void *key;                        /* ptr to enclosing struct's key  */
//    unsigned keylen;                  /* enclosing struct's key len     */
//    unsigned hashv;                   /* result of hash-fcn(key)        */
// } UT_hash_handle;


struct my_struct {
    int id;            /* we'll use this field as the key */
    char name[10];
    UT_hash_handle hh; /* makes this structure hashable */
};



void add_user(struct my_struct **users, int user_id, char *name) 
{
    // struct my_struct *s;

    // s = malloc(sizeof(struct my_struct));
    // s->id = user_id;
    // strcpy(s->name, name);
    // HASH_ADD_INT( *users, id, s );  /* id: name of key field */
    struct my_struct *s;
    HASH_FIND_INT(*users, &user_id, s);  /* id already in the hash? */
    if (s==NULL) {
      s = (struct my_struct *)malloc(sizeof *s);
      s->id = user_id;
      HASH_ADD_INT( *users, id, s );  /* id: name of key field */
    }
    strcpy(s->name, name);
}

struct my_struct *find_user(struct my_struct **users, int user_id) 
{
    struct my_struct *s;

    HASH_FIND_INT( *users, &user_id, s );  /* s: output pointer */
    return s;//NULL IF NOT FOUND
}

void delete_user(struct my_struct **users, struct my_struct *user) 
{
    HASH_DEL(*users, user);  /* user: pointer to deletee */
    free(user);             /* optional; it's up to you! */
}


void delete_all(struct my_struct **users) 
{
  struct my_struct *current_user, *tmp;

  HASH_ITER(hh, users, current_user, tmp) {
    HASH_DEL(users,current_user);  /* delete; users advances to next */
    free(current_user);            /* optional- if you want to free  */
  }
}



int main()
{
	struct my_struct *users = NULL;
	add_user(&users, 1, "12");


}