/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/
#include <iostream>

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(nullptr == root)
            return root;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *head = nullptr, *pre = nullptr;
    void dfs(Node *cur){
        if(nullptr == cur) 
            return;
        dfs(cur->left);
        if(nullptr == pre) 
            head = cur;
        else
            pre->right = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right); 
    }
};