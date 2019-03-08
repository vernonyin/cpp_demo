//
// Created by yin on 2019-02-19.
//

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL ){
            return NULL;
        }
        if(head->next == NULL){
            if(head->val == val){
                return NULL;
            }else{
                return head;
            }
        }

        ListNode tmp(0);
        tmp.next = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur){
            if(cur->val == val){
                cur = cur->next;
                continue;
            }
            pre->next = cur;
            cur = cur->next;
        }
        return tmp.next;
    }
};