#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "include/list.h"

struct foo{
	int id;
	struct list_head entry;
};

int main(){
	printf("hello world!\n");
	struct foo fo;
	INIT_LIST_HEAD(&fo.entry);
	
	struct foo *first = (struct foo *)malloc(sizeof(struct foo));
	first->id = 999;
	list_add(&first->entry,&fo.entry);

	struct foo *iterator;
	list_for_each_entry(iterator, &fo.entry, entry) {
		printf("id=%d\n",iterator->id);
	}
	
}
/*
struct list_head{
	struct list_head *pre;
	struct list_head *next;
};

struct fox{
	long number;
	struct list_head list;
};
    #define max(a,b) \
       ({ typeof (a) _a = (a); \
           typeof (b) _b = (b); \
         _a > _b ? _a : _b; })

#define offsetof2(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
	const typeof(((type *)0)->member)*__mptr = (ptr);    \
		     (type *)((char *)__mptr - offsetof2(type, member)); })


#define container_of(ptr,type,member) ({ \
	const typeof(((type *)0)->member ) *__mptr = (ptr); \
	(type * )((char *)__mptr - offsetof(type,member));})
#define list_entry(ptr,type,member) \
	container_of(ptr,type,member)
*/
