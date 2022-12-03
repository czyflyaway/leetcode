/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

*/


#include <iostream>
#include <unordered_map>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // Node* copyRandomList(Node* head) {
    //     if(!head)
    //         return head;
    //     Node *cur = head;
    //     std::unordered_map<Node*, Node*> map;
    //     while(cur != nullptr){
    //         map[cur] = new Node(cur->val);
    //         cur = cur->next;
    //     }
    //     cur = head;
    //     while(cur != nullptr){
    //         map[cur]->next = map[cur->next];
    //         map[cur]->random = map[cur->random];
    //         cur = cur->next;
    //     }
    //     return map[head];
    // }
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node *cur = head;
        while(cur){
            Node *next = cur->next;
            Node *copyed = new Node(cur->val);
            copyed->next = next;
            cur->next = copyed;
            cur = next;
        }

        cur = head;
        while(cur){
            if(cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node *res = head->next;

        Node* prev = head;
        cur = head->next;
        
        while(cur->next){
            prev->next = prev->next->next;
            cur->next = cur->next->next;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = nullptr;

        return res;
    }
};