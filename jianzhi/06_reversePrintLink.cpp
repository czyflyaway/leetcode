/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };


#include <vector>
#include <stack>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        std::stack<int> s;
        ListNode *p = head;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        std::vector<int> ret;
        while(!s.empty()){
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }
};

int main(int argc, char *argv[]){

}