/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入:      1->2->4, 
          1->3->4
输出：1->1->2->3->4->4
*/

#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2){
            return nullptr;
        }
        if(l1 && !l2){
            return l1;
        }
        if(l2 && !l1){
            return l2;
        }
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != nullptr ? l1 : l2;
        return head->next;
    }
};

int main(int argc, char *argv[]){

    return 0;
}