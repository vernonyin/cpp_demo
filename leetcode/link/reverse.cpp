/*
 * reverse.cpp
 *
 *  Created on: 2018年4月19日
 *      Author: Administrator
 *
 *      总结：
 *      第一个节点要变动的就要申请一个假节点
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
  ListNode *Reverse(ListNode *pHead) {
    //链表反转：定义两个指针，一个临时tmp缓存next

    ListNode *pre = NULL;
    ListNode *cur = pHead;
    while (cur) {
      // tmp 2 3 4
      ListNode *tmp = cur->next;
      // 1->0
      cur->next = pre;

      pre = cur;
      cur = tmp;
    }
    return pre;
  }

  //11-8
  ListNode *SwapPairs1031(ListNode *head) {

    ListNode tmp(0);
    tmp.next = head;
    ListNode* pre=&tmp;
    ListNode* cur = head;
    while(cur && cur->next){
      //0234
      pre->next = cur->next;
      //234
      pre = pre->next;
      // 134
      cur->next = pre->next;
      //2134
      pre->next = cur;

      pre = cur;
      cur = cur->next;
    }
    return tmp.next;




    //1-2-3-4
    ListNode tmp(0);
    tmp.next = head;
    ListNode *pre = &tmp;
    ListNode *cur = head;
    //注意终止条件
    while (cur && cur->next) {
      // pre0 2 3 4
      pre->next = cur->next;
      //pre 2-3-4
      pre = pre->next;
      //1-3-4
      cur->next = pre->next;
      pre->next = cur;

      pre = cur;
      cur = cur->next;
    }
    return tmp.next;


  }

  //观察指针的变化
  ListNode *SwapPairs1027(ListNode *head) {
    ListNode tmp(0);
    tmp.next = head;
    ListNode *cur = head;
    ListNode *pre = &tmp;
    while (cur && cur->next) {
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

    return tmp.next;
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
    if (head == NULL) return head;
    ListNode tmp(0);
    tmp.next = head;
    ListNode *pre = &tmp;
    ListNode *cur = head;

    while (cur && cur->next) {
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

  //公共节点：pa，pb都会遍历两条链表，遍历次数是一样的。如果没有最后为null
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;
    int lenA = 0, lenB = 0, len;
    while (pa) {
      lenA++;
      pa = pa->next;
    }
    while (pb) {
      lenB++;
      pb = pb->next;
    }
    pa = headA;
    pb = headB;

    if (lenA > lenB) {
      len = lenA - lenB;
      while (len--) {
        pa = pa->next;
      }
    } else {
      len = lenB - lenA;
      while (len--) {
        pb = pb->next;
      }
    }
    while (pa && pb) {
      if (pa == pb) {
        return pa;
      }
      pa = pa->next;
      pb = pb->next;
    }
    return NULL;

//
//
//
//
//        ListNode *pa = headA, *pb = headB;
//        while (pa != pb) {
//            // pa 1->5->3->4
//            // pb 2->3->4
//            pa = (pa != NULL) ? pa->next : headB;
//            pb = (pb != NULL) ? pb->next : headA;
//
//            /**
//             * pa:1-5-3-4-2-3-4
//             * pb:2-3-4-1-5-3-4
//             *
//             * 1-2-3
//             * 4-5-6
//             *
//             * 1-2-3-4-5-6
//             * 4-5-6-1-2-3
//             */
//        }
//        return pa;
  }

  //倒数第k个元素:保留pk和cur两个指针，同时移动
  ListNode *FindKthToTail(ListNode *head, int k) {
    ListNode *pk = head;
    ListNode *cur = head;
    int i = 0;
    while (cur) {
      if (++i >= k) {
        pk = pk->next;
      }

      cur = cur->next;
    }
    return pk;









//        ListNode *pk = head, *cur = head;
//        int i = 0;
//        while (cur) {
//
//            if (i++ >= k) {
//                pk = pk->next;
//            }
//            cur = cur->next;
//            /*
//            if (i++ >= k){
//                cur = cur->next;
//                continue;
//            }else{
//                pk = pk->next;
//                cur = cur->next;
//            }
//             */
//        }
//        return pk;
  }

  //旋转k次
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return NULL;

    ListNode *tail = head;
    //错误1：计算链表长度不对
    int length = 0;
    while (tail) {
      tail = tail->next;
      ++length;
    }

    //错误2：没有拼接成一个环
    tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = head;

    int rk = k % length;
    ListNode *pre = head;
    ListNode *cur = head;

    for (int i = 0; i < length - rk; i++) {
      pre = cur;
      cur = cur->next;
    }

    pre->next = nullptr;
    return cur;

    /*
    ListNode* pre = head;
    ListNode* cur = head;
    bool  end=false;
    while(k--){
        pre = cur;
        cur = cur->next;
        if (cur->next == NULL){
            cur->next = head;
            end = true;
        }
    }
    ListNode* h = cur;
    if (!end){
        while(cur){
            cur = cur->next;
            if (cur->next == NULL){
                cur->next = head;
               break;
            }
        }
    }
    pre->next = NULL;
    return h;

     */
  }

  ListNode *rotateRight2(ListNode *head, int k) {
    if (!head) return NULL;

    ListNode *tail = head;
    //错误1：计算链表长度不对
    int length = 1;
    while (tail->next) {
      tail = tail->next;
      ++length;
    }
    tail->next = head;

    //错误2：没有拼接成一个环
    //错误3：两个操作可以合并
    //错误4：tail又重新接上了

    int rk = k % length;
    tail = tail->next;

    ListNode *pre = head;
    for (int i = 0; i < length - rk; i++) {
      pre = tail;
      tail = tail->next;
    }

    pre->next = NULL;
    return tail;
  }

  //判断是否有环
  bool findCycle(ListNode *head) {
    //100 分
//        if (head == nullptr)return head;
//        ListNode* first =head;
//        ListNode* second = head;
//        while(second->next && second->next->next){
//            first = first->next;
//            second = second->next->next;
//            if (first == second){
//                return true;
//            }
//        }
//        return false;







    if (!head)
      return false;

    ListNode *first = head, *second = head;

    //错误1：判断是否为空
    while (second->next && second->next->next) {
      first = first->next;
      second = second->next->next;
      if (first == second) {
        return true;
      }
    }
    return false;
  }


  ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *firstp = head;
    ListNode *secondp = head;
    bool isCycle = false;

    while (firstp != NULL && secondp != NULL) {
      firstp = firstp->next;
      if (secondp->next == NULL) return NULL;
      secondp = secondp->next->next;
      if (firstp == secondp) {
        isCycle = true;
        break;
      }
    }

    if (!isCycle) return NULL;
    firstp = head;
    while (firstp != secondp) {
      firstp = firstp->next;
      secondp = secondp->next;
    }

    return firstp;
  }

  //保留一个
  ListNode *deleteDuplication3(ListNode *pHead) {
    ListNode *cur = pHead->next;
    ListNode *pre = pHead;
    //1-1-2-2-2-3
    //pre pos1 pos2
    while (cur) {
      if (pre->val == cur->val) {
        pre->next = cur->next;
      } else {
        pre = pre->next;
      }

      cur = cur->next;
    }
//        return pHead;
    ListNode *current = pHead;
    while (current != NULL && current->next != NULL) {
      if (current->next->val == current->val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }
    return pHead;
  }

  ListNode *deleteDuplication2(ListNode *pHead) {
    if (!pHead || !pHead->next) return pHead;

    ListNode tmp(0);
    tmp.next = pHead;
    ListNode *pre = &tmp;
    ListNode *cur = pHead;
    //1,2,2,3,4
//        //pre 0-1-2-2-3-4
    // 0 -cur 1-2-2-3-4
    while (cur) {
      if (cur->next && pre->next->val == cur->next->val) {
        do {
          cur = cur->next;
        } while (cur->next && pre->next->val == cur->next->val);
        pre->next = cur->next;
      } else {
        pre = pre->next;
      }


      cur = cur->next;
    }
    return tmp.next;
  }

  //https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
  //删除重复的 重复的不保留
  ListNode *deleteDuplication(ListNode *pHead) {
    if (!pHead || !pHead->next) return pHead;

    ListNode tmp(0);
    tmp.next = pHead;
    ListNode *pre = &tmp;
    ListNode *cur = pHead;
    //1,2,2,3,4
//        //pre 0-1-2-2-3-4
    // 0 -cur 1-2-2-3-4
    while (cur) {
      if (cur->next && pre->next->val == cur->next->val) {
        do {
          cur = cur->next;
        } while (pre->next->val == cur->next->val);
        pre->next = cur->next;
      } else {
        pre = pre->next;
      }


      cur = cur->next;
    }
    return tmp.next;
//
//        ListNode* cur = pHead->next;
//        ListNode* pre = pHead;
//        //1-1-2-2-2-3
//        //pre pos1 pos2
//        while(cur){
//            if (pre->val == cur->val){
//                pre->next = cur->next;
//            }else{
//                pre = pre->next;
//            }
//
//            cur = cur->next;
//        }
//        return pHead;
  }

  ListNode *deleteDuplicates1208(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *cur = head->next;
    ListNode *pre = head;
    while (cur) {
      if (pre->val == cur->val) {
        cur = cur->next;
      } else {
        pre->next = cur;
        pre = pre->next;
        cur = cur->next;
      }
    }
    pre->next = NULL;
    return head;
//    ListNode* cur = head;
//    while(cur) {
//      while(cur->next && cur->val == cur->next->val) {
//        cur->next = cur->next->next;
//      }
//      cur = cur->next;
//    }
//    return head;
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head(0);
    ListNode* pM = &head;
    while(l1 && l2){
      if (l1->val < l2->val){
        pM->next = l1;
        l1=l1->next;
      }else{
        pM->next = l2;
        l2=l2->next;
      }
      pM = pM->next;
    }
    if (l1){
      pM->next = l1;
    }
    if (l2){
      pM->next = l2;
    }
    return head.next;

//
//    ListNode* pM = NULL;
//    if (l1 == NULL){
//      return l2;
//    }
//    if (l2 == NULL){
//      return l1;
//    }
//    if (l1->val < l2->val){
//      pM = l1;
//      l1=l1->next;
//    }else{
//      pM = l2;
//      l2=l2->next;
//    }
//    ListNode* pHead = pM;
//    while(l1 && l2){
//      if (l1->val < l2->val){
//        pM->next = l1;
//        l1=l1->next;
//      }else{
//        pM->next = l2;
//        l2=l2->next;
//      }
//      pM = pM->next;
//    }
//    if (l1){
//      pM->next = l1;
//    }
//    if (l2){
//      pM->next = l2;
//    }
//    return pHead;
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

ListNode *NewArray(int *arr, int num) {
  ListNode *head = new ListNode(arr[0]);
  ListNode *cur = head;
  for (int i = 1; i < num; i++) {
    ListNode *node = new ListNode(arr[i]);
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

enum {
  REVERSE,
  SWAP,
  intersection,
  FindKthToTail,
  rotateRight,
  deleteDuplication,
  Merge,
};

int main() {
  Solution s;
  ListNode *link = New(3);

  int arr[] = {1,3,5};
  ListNode *linkArr = NewArray(arr, 3);


  int arr2[] = {2,4,6};
  ListNode *linkArr2 = NewArray(arr, 3);

  int i = Merge;
  int test = 0 + i;

  if (test == Merge) {
    Print(linkArr);
    link = s.mergeTwoLists(linkArr,linkArr2);
    Print(linkArr);
  }else if (test == deleteDuplication) {
    Print(linkArr);
    link = s.deleteDuplicates1208(linkArr);
    Print(linkArr);
  } else if (test == REVERSE) {
    Print(link);
    link = s.Reverse(link);
    Print(link);
  } else if (test == SWAP) {
    Print(link);
    link = s.SwapPairs1027(link);
    Print(link);
  } else if (test == intersection) {
    ListNode *link2 = new ListNode(0);
    link2->next = link->next->next;
    Print(link);

    link = s.getIntersectionNode(link, link2);
    printf("======getIntersectionNode=======\n");
    Print(link);

    ListNode *link3 = new ListNode(0);
    link = s.getIntersectionNode(link, link3);
    printf("======getIntersectionNode=======\n");
    Print(link);
  } else if (test == FindKthToTail) {
    ListNode *kNode = s.FindKthToTail(link, 5);
    printf("======FindKthToTail=======\n");
    Print(kNode);
  } else if (test == rotateRight) {
    ListNode *kNode = s.rotateRight2(link, 4);
    printf("======rotateRight=======\n");
    Print(kNode);
  }

  return 0;
}


