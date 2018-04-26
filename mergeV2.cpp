/*
 * reverse.cpp
 *
 *  Created on: 2018年4月19日
 *      Author: Administrator
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1){
			printf("merge pHead1 empty\n");
			return pHead2;
		}

		if (!pHead2){
			printf("merge pHead1 empty\n");
			return pHead1;
		}
		
		ListNode *begin= NULL;
		ListNode *cur = begin;
		if(pHead1->val > pHead2->val){
			cur = begin = pHead2;
			pHead2 = pHead2->next;	
		}else{
			cur = begin = pHead1;
			pHead1 = pHead1->next;
		}	
		while (pHead1 && pHead2) {
			if (pHead1->val > pHead2->val) {
				printf("pHead1 > pHead2\n");
				begin->next = pHead2;
				begin = pHead2;
				pHead2 = pHead2->next;
			} else {
				printf("pHead1 < pHead2\n");
				begin->next = pHead1;
				begin = pHead1;
				pHead1 = pHead1->next;
			}
		}
		if (pHead1) {
			printf("pHead1\n");
			begin->next = pHead1;
		}
		if (pHead2) {
			printf("pHead2\n");
			begin->next = pHead2;
		}
		return cur;
	}
};

/*
 * 1、循环后会变化
 * 2、
 * */

int main() {
	Solution s;
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	for (int i = 1; i < 10; i += 2) {
		ListNode* node = new ListNode(i);
		node->val = i;
		node->next = NULL;
		cur->next = node;
		cur = node;
		printf("address=%p,val=%d\n", node, i);
	}
	cur->next = NULL;

	cur = head;

	ListNode* head2 = new ListNode(0);
	ListNode* cur2 = head2;
	for (int i = 2; i < 20; i += 2) {
		ListNode* node = new ListNode(i);
		node->val = i;
		node->next = NULL;
		cur2->next = node;
		cur2 = node;
		printf("address=%p,val=%d\n", node, i);
	}
	cur2->next = NULL;

	cur2 = head2;
	//dowhile 打印
//	do {
//		printf("before list address=%p, val=%d\n", cur, cur->val);
//	} while (cur = cur->next);

//	cur = s.ReverseList(head);
	cur = s.Merge(cur, cur2);
	do {
		printf("before list val=%d\n", cur->val);
	} while (cur = cur->next);

	return 0;
}


