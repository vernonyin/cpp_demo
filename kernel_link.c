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
    list_add(&second->entry,&fo.entry);

    struct foo *iterator;
    list_for_each_entry(iterator, &fo.entry, entry) {
        printf("id=%d\n",iterator->id);
    }

}
