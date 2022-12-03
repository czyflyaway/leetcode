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
    //迭代
    ListNode* reverseList(ListNode* head) {
        // if(!head || !(head->next)){
        //     return head;
        // }
        // ListNode *cur = head->next;
        // ListNode *pre = head;
        // head->next = nullptr;
        // while(cur){
        //     ListNode *temp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = temp;
        // }
        // return pre;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur){
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    //递归
    ListNode* reverseList_1(ListNode* head) {
        ListNode *pre = nullptr;
        reverse(pre, head);
        return pHead;
    }

private:
    ListNode *pHead = nullptr;
    void reverse(ListNode *pre, ListNode *pcur){
        if(!pcur){
            pHead = pre;
            return;
        }
        ListNode *temp = pcur->next;
        pcur->next = pre;
        pre = pcur;
        pcur = temp;
        reverse(pre, pcur);
    }

};


int main(int argc, char *argv[]){

    {
        //边界1，为空
        ListNode *l1 = makeArrToList({});
        Solution sol;
        ListNode *head = sol.reverseList(l1);
        printListNode(head);
    }
    {
        //边界1，为空
        ListNode *l1 = makeArrToList({1});
        Solution sol;
        ListNode *head = sol.reverseList(l1);
        printListNode(head);
    }
    {
        //边界1，为空
        ListNode *l1 = makeArrToList({1, 2});
        Solution sol;
        ListNode *head = sol.reverseList(l1);
        printListNode(head);
    }

    {
        ListNode *l1 = makeArrToList({1,2,3,4, 5,6,7});
        Solution sol;
        ListNode *head = sol.reverseList(l1);
        printListNode(head);
    }

    {
        //边界1，为空
        ListNode *l1 = makeArrToList({});
        Solution sol;
        ListNode *head = sol.reverseList_1(l1);
        printListNode(head);
    }
    {
        //边界1，为空
        ListNode *l1 = makeArrToList({1});
        Solution sol;
        ListNode *head = sol.reverseList_1(l1);
        printListNode(head);
    }
    {
        //边界1，为空
        ListNode *l1 = makeArrToList({1, 2});
        Solution sol;
        ListNode *head = sol.reverseList_1(l1);
        printListNode(head);
    }

    {
        ListNode *l1 = makeArrToList({1,2,3,4, 5,6,7});
        Solution sol;
        ListNode *head = sol.reverseList_1(l1);
        printListNode(head);
    }
}