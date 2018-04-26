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
 ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead || !pHead->next){
            return pHead;
        }
        if(!pHead->next->next && pHead->next->val == pHead->val){
            return NULL;
        }
        if(!pHead->next->next && pHead->next->val != pHead->val){
            return pHead;
        }
		ListNode* cur = pHead;
        ListNode* nxt0 = pHead;
        ListNode* nxt1 = pHead->next;
        ListNode* nxt2 = nxt1->next;
		if( nxt0->val == nxt1->val ){
			printf("equal ==0\n");
			cur = nxt2;
			nxt0=nxt2;
			nxt1=nxt0->next;
			nxt2=nxt1->next;
		}
        while(nxt2){
			printf("val %d %d %d\n",nxt0->val,nxt1->val,nxt2->val);	
            if(nxt1->val == nxt2->val){
				printf("equel\n");
             	nxt1 = nxt2->next;
                if(!nxt1){
					printf("break nxt1\n");
                    break;
				}
                nxt2 = nxt1->next;
                if(!nxt2){
					printf("break nxt2\n");
                    nxt0->next = nxt1;
                    break;
                }
				continue;
			}
			printf("after val %d %d %d %p--\n",nxt0->val,nxt1->val,nxt2->val,nxt0);	
			
			if(!nxt0->next){
				printf("----\n");
				break;
			}
			//next 一定要伴随赋值
            nxt0->next = nxt1;
            nxt0 = nxt1;
            nxt1 = nxt0->next;
            nxt2 = nxt1->next;
			printf("after val %d %d --\n",nxt0->val,nxt1->val);	
        }
		printf("end\n");
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
	for (int i = 1; i < 10; i ++) {
		ListNode* node = new ListNode(i);
		int v = i;
		if (i == 4) v=3;
		if (i == 6) v=5;
		node->val = v;
		node->next = NULL;
		cur->next = node;
		cur = node;
	}
	cur->next = NULL;

	cur = head;

	do {
		printf("before list val=%d\n", cur->val);
	} while (cur = cur->next);

	cur = head;
	cur = s.deleteDuplication(cur);
	do {
		printf("before list val=%d\n", cur->val);
	} while (cur = cur->next);

	return 0;
}


