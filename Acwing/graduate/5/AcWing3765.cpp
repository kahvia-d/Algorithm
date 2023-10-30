//
// Created by Kahiva on 2023/10/30.
//
//https://www.acwing.com/problem/content/3768/
//表达式树


#include "iostream"

using namespace std;

struct TreeNode {
  string val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
public:

    string dfs(TreeNode* root){
        //判断结点是否为空（由题当运算符是负号时，左儿子为空）
        if (!root) return "";
            //结点是叶节点，即节点值是被操作数的时候，返回操作数
        else if(!root->left && !root->right) return root->val;
            //非叶子结点时，返回左表达式 操作符 右表达式，并添加括号
        else return '(' + dfs(root->left) + root->val + dfs(root->right) + ')';
    }

    string expressionTree(TreeNode* root) {
        return dfs(root->left) + root->val + dfs(root->right);
    }
};
