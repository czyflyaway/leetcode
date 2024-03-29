/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur){
            ListNode *p = cur->next;
            cur->next = prev;
            prev = cur;
            cur = p;     
        }
        return prev;
    }
};
int main(int argc, char *argv[]){

}