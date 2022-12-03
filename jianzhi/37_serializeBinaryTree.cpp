/*
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。
这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
*/


#include <iostream>
#include <list>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void rserialize(TreeNode *root, string &ret){
        if(nullptr == root){
            ret += "None,";
        } else{
            ret += to_string(root->val) + ",";
            rserialize(root->left, ret);
            rserialize(root->right, ret);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode *rdeserialize(list<string> &dataArray){
        if("None" == dataArray.front()){
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for(auto ch : data){
            if(',' == ch){
                dataArray.push_back(str);
                str.clear();
            } else{
                str.push_back(ch);
            }
        }

        if(!str.empty()){
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};