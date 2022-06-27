#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
ListNode *copy(ListNode *src)
{
    if(!src)    return nullptr;
    ListNode *tmpSrc = src;
    ListNode *head = new ListNode(tmpSrc->val);
    ListNode *tmp = head;
    tmpSrc = tmpSrc->next;
    while(tmpSrc){
        ListNode *node = new ListNode(tmpSrc->val);
        tmp->next = node;
        tmp = node;
    }
    return head;
}
void copy(ListNode **dest, ListNode **src){
    while(*src){
        *dest = new ListNode((*src)->val);
        dest = &((*dest)->next);
        src = &((*src)->next);
    }
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if(!l1 && !l2)  return nullptr;
        // if(!l1)         return copy(l2);
        // if(!l2)         return copy(l1);

        ListNode *preResult     = new ListNode;
        ListNode *tempL1        = l1;
        ListNode *tempL2        = l2;
        ListNode *tmp           = preResult;
        int lastSum = 0;
        while(tempL1 || tempL2){
            int numL1 = 0;
            int numL2 = 0;
            if(tempL1)
                numL1 = tempL1->val;
            if(tempL2)
                numL2 = tempL2->val;

            int sum = numL1 + numL2 + lastSum;
            int num = sum;
            if(sum >= 10){
                num = sum - 10;
                lastSum = 1;
            }
            else{
                lastSum = 0;
            }
            ListNode *node = new ListNode(num);
            tmp->next = node;
            tmp = node;

            if(tempL1)
                tempL1 = tempL1->next;
            if(tempL2)
                tempL2 = tempL2->next;
        }
        if(lastSum){
            ListNode *node = new ListNode(lastSum);
            tmp->next = node;
            tmp = node;
        }
        return preResult->next;
    }
};

int main(int argc, char *argv[]){
    // {
    //     //test copy
    //     ListNode *dest;
    //     std::vector<int> l1= {2,4,3};
    //     ListNode *l1_head = makeArrToList(l1);
    //     copy(&dest, &l1_head);
    //     printListNode(dest);
    //     return 1;
    // }
    {
        std::vector<int> l1= {2,4,3};
        ListNode *l1_head = makeArrToList(l1);
        printListNode(l1_head);    

        std::vector<int> l2 = {5,6,4};
        ListNode *l2_head = makeArrToList(l2);
        printListNode(l2_head);

        Solution sol;
        ListNode *lresult = sol.addTwoNumbers(l1_head, l2_head);   
        printListNode(lresult);
    }

    {
        std::vector<int> l1= {9,9,9,9,9,9,9};
        ListNode *l1_head = makeArrToList(l1);
        printListNode(l1_head);    

        std::vector<int> l2 = {9,9,9,9};
        ListNode *l2_head = makeArrToList(l2);
        printListNode(l2_head);

        Solution sol;
        ListNode *lresult = sol.addTwoNumbers(l1_head, l2_head);   
        printListNode(lresult);
    }
    return 0;
}