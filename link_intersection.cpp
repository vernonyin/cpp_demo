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

/*
 *题目：
 * 输入两个链表，找出它们的第一个公共结点。
 *
 * */

struct ListNode {
         int val;
         struct ListNode *next;
     };

#define null NULL

class Solution {

public:
    //暴力破解
    ListNode getIntersectionNode(ListNode headA, ListNode headB) {

    }
};

//新建链表
ListNode *New(int num) {
    ListNode *head = new ListNode;
    ListNode *cur = head;
    for (int i = 2; i <= num; i++) {
        ListNode *node = new ListNode;
        node->val = i;
        cur->next = node;
        cur = node;
    }
    return head;
}

//打印链表
void Print(const ListNode *l) {
    printf("=============================\n");
    while (l) {
        printf("list %p %d\n", l, l->val);
        l = l->next;
    }
}

int main() {
    Solution s;
    ListNode *link1 = New(10);
    Print(link1);

    ListNode* link2 = link1->next->next;

    return 0;
}


