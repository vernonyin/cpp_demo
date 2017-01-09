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
    struct foo *second= (struct foo *)malloc(sizeof(struct foo));
    first->id = 999;
    second->id = 888;
    list_add(&first->entry,&fo.entry);
    list_add_tail(&second->entry,&fo.entry);
//    list_add_tail(&second->entry,&fo.entry);

    struct foo *iterator;
    list_for_each_entry(iterator, &fo.entry, entry) {
        printf("id=%d\n",iterator->id);
    }

	struct foo  *next;
	list_for_each_entry_safe(iterator, next, &fo.entry, entry) {
		//	list_del(&iterator->entry);
//		free(iterator);
	}
	printf("empty ? %d\n",list_empty(&fo.entry));
	// 这里用到了contain_of 或者entry在数据结构中的位置
	first = list_first_entry(&fo.entry, struct foo, entry);

    list_for_each_entry(iterator, &fo.entry, entry) {
        printf("id=%d\n",iterator->id);
    }
	free(first);
	free(second);
}
