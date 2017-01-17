//cmake -DCMAKE_BUILD_TYPE=Debug .. -Dfile=link.cpp
#include <stdio.h>
#include <stdlib.h>
#include "include/my_list.h"

struct fox {
	struct list_element *list_of_el;
};

struct list_element {
	void *data;
	struct list_element *next;
};

int main()
{
	printf("fox size=%d\n", sizeof(struct fox));
	printf("list_element size=%d\n", sizeof(struct list_element));
	char *str1 = "hello";
	char *str2 = " world";

	struct fox *st= (struct fox *) malloc(sizeof(struct fox));
	st->list_of_el = NULL;
	if (list_empty(st->list_of_el))
	{
		printf("link empty\n");
	} else
	{
		printf("link not empty\n");
	}

	//第一个可能为空
	struct list_element *pos1 ;
	printf("pos1 addr=%lu\n",pos1);
	//insert
	for (int i = 0; i < 10; i++)
	{
		struct list_element *lec2 = (struct list_element *) malloc(sizeof(struct list_element));
		lec2->data = (void *) i;
		lec2->next = NULL;

		list_add(st->list_of_el, lec2);
//		printf("===%d %d\n",st->list_of_el,pos1);
		struct list_element *pos = NULL;
		pos = st->list_of_el;
		while(pos){
			printf("---- foreach data=%d\n", pos->data);
			pos = pos->next;
		}
	}
	//foreach 指针不能回去
	struct list_element *pos = NULL;
	list_for_each_entry(pos, st->list_of_el)
	{
		printf("before del foreach data=%d\n", pos->data);
	}
	printf("====== %d",st->list_of_el);
	//delete
	list_del(st->list_of_el,pos1,pos);	
	list_for_each_entry(pos, st->list_of_el)
	{
		printf("after del foreach data=%d\n", pos->data);
	}

	exit(0);
}
