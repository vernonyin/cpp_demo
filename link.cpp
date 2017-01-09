//cmake -DCMAKE_BUILD_TYPE=Debug .. -Dfile=link.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct list_element{
	void* data;
	struct list_element* next;
};

int main(){
	cout<<"hello world!"<<endl;
	char *str1="hello";
	char *str2=" world";
/* 用非指针不用malloc是因为从栈上直接分配了 */
	list_element le;
	list_element le2;
	le.data = (void*)str1;
	le.next = &le2;
	le2.data = (void*)str2;
	le2.next = NULL;
	printf("le.data=%s\n",le.data);
	printf("le.next.data=%s\n",le.next->data);
/* 
这样会coredump因为指针要malloc指向内存未分配
	指针根本就没有指向一个实际内存中!!!
	malloc return void*
	todo：如何看coredump文件
 */ 
	list_element *lec=(list_element *)malloc(sizeof(struct list_element));
	lec->data = (void*)str1;
	lec->next = NULL;
	printf("point le.data=%s\n",lec->data);
	free(lec);
	list_element *l1,*l2;



/*
	链表要用head->next 判断，因为head为空的时候就没有地址了啊！！！

*/
	list_element *link= NULL;
	list_element *head= NULL;
	list_element *head2= NULL;
	list_element *item = (list_element *)malloc(sizeof(struct list_element));	
	item->data = (void*)999;
	item->next = NULL;
	link = item;
	head = item;
	printf("item addr %ld\n",item);
/*
	list_element *item2 = (list_element *)malloc(sizeof(struct list_element));	
	item2->data = (void*)444;
	item2->next = NULL;

	while(head->next != NULL){
		head = head->next;
		cout<<"while i="<<endl;
}

	head->next  = item2;
	printf("item2 addr %ld\n",item2);
	printf("head addr %ld\n",head);
	printf("link addr %ld\n",link);
*/
	for(int i=0;i<10;i++){
		list_element *item = (list_element *)malloc(sizeof(struct list_element));	
		item->data = (void*)i;
		item->next = NULL;
		while(head->next){
			head = head->next;
			cout<<"while i="<<i<<endl;
		}
		head->next = item;
		cout<<"i="<<i<<endl;
	}
	while(link){
		printf("print %d\n",link->data);
		link= link->next;
	}
	cout<<"end..."<<endl;



}

