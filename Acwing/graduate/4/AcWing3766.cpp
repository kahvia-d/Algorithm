//
// Created by Kahiva on 2023/10/26.
//
//https://www.acwing.com/problem/content/3769/
//二叉树的带权路径长度

#include "iostream"

struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:

    int dfs(TreeNode* root, int dep){
        //如果是空树，返回0
        if(root == NULL) return 0;
        //如果是叶子结点，返回权值乘以深度
        if(root->left == NULL && root->right == NULL) return dep * root->val;
        //如果是有儿子的结点
        return dfs(root->left, dep + 1) + dfs(root->right, dep + 1);
    }

    int pathSum(TreeNode* root) {
        return dfs(root, 0);
    }
};
