/**
原因好处：w
1、内部定义临时变量

**/


#define list_empty(head) \
        head == NULL

/*
do{}while(0) 好处:可以break;
type((entry)+1)好处防止传入非指针或数组，高！
*/
#define list_add(head,entry) do{\
	if(head == NULL ){\
		head = entry;\
		break;\
	}\
	if (head->next == NULL){\
		pos = head;\
		head->next = entry;\
		break;\
	}\
	typeof((entry)+1) pos1 = head;\
	while(head->next){\
		head = head->next;\
	}\
	head->next = entry;\
	head = pos1;\
	}\
while(0)

//判断下一个是否相等就行了啊
#define list_del(head,entry,pos) do{\
	if (head == NULL || entry == NULL)\
		break;\
	if(head->next == NULL){\
		if(head == entry){\
			head = NULL;\
		}\
		break;\
	}\
	while(head->next != entry && head != NULL){\
		head = head->next;\
	}\
	if(head != NULL){\
		head->next=head->next->next;\
	}\		
	}while(0)
		

#define list_for_each_entry(pos, head)				\
    for(pos = head;pos;head=head->next,pos=head)




