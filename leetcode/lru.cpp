
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

class DLinkedNode{
public:
    int val;
    int key;
    DLinkedNode* pre;
    DLinkedNode* next;

    DLinkedNode():key(0),val(0),pre(nullptr),next(nullptr){}
    DLinkedNode(int k,int v):key(k),val(v),pre(nullptr),next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int _capacity) :capacity(_capacity),size(0){
      head = nullptr;
      tail = nullptr;
    }

    int get(int key) {
      if(data.count(key) == 0){
        return -1;
      }
      DLinkedNode* node = data[key];
      if(node == head && size > 1){
        head = node->next;
      }

      DLinkedNode* _pre = node->pre;
      DLinkedNode* _next = node->next;
      //说明是最后一个，不用移动
      if(_next == nullptr){
        return node->val;
      }

      //表头
      if(_pre == nullptr){
        head = node->next;
      }else{
        _pre->next = _next;
      }
      _next->pre = _pre;
      tail->next = node;
      node->next = nullptr;
      node->pre = tail;
      tail = node;
      return node->val;
    }

    void put(int key, int value) {

      //put 也需要get一次
      if(data.count(key) > 0){
        data[key]->val = value;
        get(key);
        return ;
      }
      //需要进行淘汰
      if(size >= capacity){
        DLinkedNode* tmp = head;
        head = head->next;
        if(head){
          head->pre = nullptr;
        }
        size--;
        data.erase(tmp->key);
        delete tmp;
      }
      DLinkedNode* node = new DLinkedNode(key,value);
      if(head == nullptr){
        tail = node;
        head = node;
      }else{
        tail->next = node;
        node->pre = tail;
        tail = node;
      }
      data[key] = node;
      ++size;
    }

    int capacity;
    unordered_map<int,DLinkedNode*> data;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
};

int main(){
//  ["LRUCache","put","put","put","put","get","get"]
//  [[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]

  LRUCache lru(2);
  lru.put(2,1);
  lru.put(1,1);
  lru.put(2,3);
  lru.put(4,1);
  cout<<"get =="<<lru.get(1)<<endl;
  cout<<"get =="<<lru.get(2)<<endl;

  /*["LRUCache","put","get","put","get","get"]
[[1],[2,1],[2],[3,2],[2],[3]]
   */
//  LRUCache lru(1);
//  lru.put(2,1);
//  cout<<"get =="<<lru.get(2)<<endl;
//  lru.put(3,2);
//  cout<<"get =="<<lru.get(2)<<endl;
//  cout<<"get =="<<lru.get(3)<<endl;

//
//  LRUCache lru(2);
//  lru.put(1,1);
//  lru.put(2,2);
//  cout<<"get =="<<lru.get(1)<<endl;
//  lru.put(3,3);
//  cout<<"get =="<<lru.get(2)<<endl;

}