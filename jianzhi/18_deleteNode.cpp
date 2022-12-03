/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
*/

#include <iostream>
#include <vector>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode * makeArrToList(const std::vector<int> &vec){
    if(0 == vec.size())
        return nullptr;
    ListNode *head = new ListNode(vec.at(0));
    ListNode *temp = head;
    for(int i = 1; i < vec.size(); ++i){
        ListNode *node = new ListNode(vec[i]);
        temp->next = node;
        temp = node;
    }
    return head;
}

void printListNode(ListNode *listNode){
    while(listNode){
        cout << listNode->val << "\t";
        listNode = listNode->next;
    }
    cout << "\n";
}
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head){
            return head;
        }
        if(head->val == val){
            ListNode *pNext = head->next;
            delete head;
            return pNext;
        }
        ListNode *prev = head;
        ListNode *next = head->next;
        while(next){
            if(next->val == val){
                  prev->next = next->next;
                  delete next;
                  break;  
            }
            prev = next;
            next = next->next;           
        }
        return head;
    }
    ListNode* deleteNode1(ListNode* head, int val) {
        if(!head){
            return head;
        }
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *prev = tmp;
        ListNode *next = tmp->next;
        while(next){
            if(next->val == val){
                  prev->next = next->next;
                  delete next;
                  break;  
            }
            prev = next;
            next = next->next;           
        }
        return tmp->next;
    }
};

int main(int argc, char *argv[]){

    std::vector<int> l1= {-3,5,-99};
    ListNode *l1_head = makeArrToList(l1);
    Solution sol;
    printListNode( sol.deleteNode(l1_head, -3));
    
    return 0;
}