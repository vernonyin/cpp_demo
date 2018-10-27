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
 * 单项链表就是一个起始的栈
 *
 * */

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    //相当于pre维护反向链表栈
    /*
    *  [pre] ->[b] -> [a]
    *
    * [cur]->[c]->[d]
    *
    * */
    ListNode* Reverse1027(ListNode* head){
        ListNode* cur = head;
        ListNode* pre =NULL;
        while (cur){
            ListNode* tmp = cur->next;

            cur->next = pre;

            pre = cur;
            cur=cur->next;
        }
        return pre;
    }


    ListNode *Reverse(ListNode *pHead) {
        ListNode *pre = NULL;
        ListNode *cur = pHead;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;

            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* SwapPairs102722(ListNode *head) {
        ListNode tmp(0);
        tmp.next = head;
        ListNode *cur = head;
        ListNode *pre = &tmp;
        while (cur && cur->next) {
            pre->next = cur->next;
            pre = cur->next;
            cur->next = pre->next;
            pre->next = cur;

            pre = cur;
            cur = cur->next;

        }
        return tmp.next;
    }

    ListNode* SwapPairs1027(ListNode *head){
        ListNode tmp(0);
        tmp.next = head;
        ListNode* cur = head;
        ListNode* pre = &tmp;
        while(cur && cur->next){
            // [pre0] 2->3->4
            pre->next = cur->next;
            // [pre 2]->3->4
            pre = cur->next;
            // cur 1->3->4
            cur->next = pre->next;
            // pre 2->1->3->4
            pre->next = cur;

            pre = cur;
            cur = cur->next;
            //已经完成转换了
            pre = cur;
            cur = cur->next;
        }

        return  tmp.next;
    }


    /*
     *   [1]   ->  [2] ->[3]->[4]
     * 0、初始
       [tmp pre] -> [cur 1]->[2] ->[3]->[4]
     * [pre] -> [1]->[2] ->[3]->[4]
     * [cur 1]-> [2] ->[3]->[4]
     *
     * 1、 只有两个指针   pre->next = cur->next;
     * [tmp pre 0] -> [2] ->[3]->[4]
     * [pre 0] -> [2] ->[3]->[4]
     * [cur 1] -> [2] ->[3]->[4]  没变
     *
     * 2、 pre = cur->next;
     * [tmp 0] -> [pre 2] ->[3]->[4]
     * [pre 2]->[3]->[4]
     * [cur 1]->[2]->[3]->[4]  没变
     *
     * 3、  cur->next = pre->next;
     * [tmp 0] -> [pre 2] ->[3]->[4] 没变
     * [pre 2] ->[3]->[4] 没变
     * [cur 1] ->[3]->[4]
     *
     * 4、pre->next = cur;
     * [tmp 0] -> [pre 2] ->[1]->[3]->[4]
     * [pre 2] ->[1]->[3]->[4]
     * [cur 1] ->[3]->[4]
     *
     * 5、 pre = cur;
     * [tmp 0] -> [2] ->[pre 1]->[3]->[4]
     * [pre 1] ->[3]->[4]
     * [cur 1] ->[3]->[4]
     *
     * 6、 cur = cur->next;
     * [tmp 0] -> [2] ->[pre 1]->[cur 3]->[4]
     * [pre 1] ->[3]->[4]
     * [cur 3] ->[4]
     * */
    ListNode *SwapPairsMy2(ListNode *head) {
        if (head ==NULL) return head;
        ListNode tmp(0);
        tmp.next = head;
        ListNode *pre = &tmp;
        ListNode * cur = head;

        while (cur && cur->next){
            pre->next = cur->next;
            pre = pre->next;

            cur->next = pre->next;
            pre->next = cur;

            pre = cur;
            cur = cur->next;
        }
        return tmp.next;

    }

    ListNode *SwapPairs(ListNode *head) {
        if (!head) return NULL;
        ListNode tmp(0);
        tmp.next = head;
        ListNode *pre = &tmp, *cur = head;
        while (cur && cur->next) {

            pre->next = cur->next;
            pre = cur->next;

            cur->next = pre->next;
            pre->next = cur;
            //已经完成转换了
            pre = cur;
            cur = cur->next;
        }
        return tmp.next;
    }


};

/*
 * 1、循环后会变化
 * 2、
 * */

//新建链表
ListNode *New(int num) {
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (int i = 2; i <= num; i++) {
        ListNode *node = new ListNode(i);
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
    ListNode *link = New(4);
    Print(link);


    link = s.Reverse(link);
    Print(link);
    link = s.Reverse(link);

    link = s.SwapPairs1027(link);
    Print(link);

    return 0;
}


