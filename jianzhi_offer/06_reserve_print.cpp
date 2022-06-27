#include <iostream>
#include <vector>
#include <stack>
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

void printVector(const vector<int> &nums){
    for(auto v : nums){
        cout << v << '\t';
    }
    cout << '\n';
}
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int > result;
        stack<int> reverseStack;
        ListNode *tmp = head;
        while(tmp){
            reverseStack.push(tmp->val);
            tmp = tmp->next;
        }
        while(!reverseStack.empty()){
            result.push_back(reverseStack.top());
            reverseStack.pop();
        }
        return result;
    }
};

int main(int argc, char *argv[]){
    {
        ListNode *l1 = makeArrToList({1,3,2,5,6,7});
        printListNode(l1);

        Solution sol;
        printVector(sol.reversePrint(l1));
    }
}