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
#include <vector>
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
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		ListNode *cur = begin;
		if(pHead1->val > pHead2->val){
			cur = begin = p2;
			p2 = p2->next;	
		}else{
			cur = begin = p2;
			p2 = p2->next;
		}	
		while (p1 && p2) {
			if (p1->val > p2->val) {
				printf("p1 > p2\n");
				begin->next = p2;
				begin = p2;
				p2 = p2->next;
			} else {
				printf("p1 < p2\n");
				begin->next = p1;
				begin = p1;
				p1 = p1->next;
			}
		}
		if (p1) {
			printf("p1\n");
			begin->next = p1;
		}
		if (p2) {
			printf("p2\n");
			begin->next = p2;
		}
		return cur;
	}

	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode tmp(0);
		ListNode* res=&tmp;
		while(pHead1 && pHead2){
			if (pHead1->val < pHead2->val){
				res->next = pHead1;
				pHead1 = pHead1->next;
			}else{
				res->next = pHead2;
				pHead2 = pHead2->next;
			}
			res = res->next;
		}
		if(pHead1){
			res->next = pHead1;
		}
		if(pHead2){
			res->next = pHead2;
		}
		return tmp.next;
	}

	int minimumTotal(vector<vector<int>>& triangle) {
		int depth = triangle.size();
		vector<vector<int > > dp[100][100];
		for(int i=0;i<triangle[depth-1].size();i++){
			dp[depth-1][i] = triangle[depth-1][i];
		}
		for(int i=depth-1;i>=0;i--){
			for (int j=0;j<triangle[i].size();j++){
				dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
			}
		}

		return dp[0][0];
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
	cur = s.Merge2(cur, cur2);
	do {
		printf("before list val=%d\n", cur->val);
	} while (cur = cur->next);

	return 0;
}


