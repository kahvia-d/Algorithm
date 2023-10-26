//
// Created by Kahiva on 2023/10/26.
//
//https://www.acwing.com/activity/content/code/content/7025387/
//AcWing 18. 重建二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        //对空树进行判断
        if (pl > pr) return NULL;

        //先序区间的首个元素必定是子树的根节点，获取它的位置
        int k = pos[preorder[pl]];
        //创建树结点保存根节点
        auto node = new TreeNode(preorder[pl]);
        //根据根节点在中序遍历中的位置，区分左右子树。
        //ps：根据中序遍历中根节点的左侧即左子树的长度，可以确定先序中的左侧子树的结点区间，因为它们长度相同。
        //对左右子树做相同的递归操作即可。
        node -> left = build(preorder, inorder, pl + 1, pl + k - il, il, k - 1);
        node -> right = build(preorder, inorder, pl + k - il + 1, pr, k + 1, ir);

        //最后返回构造完毕的根节点
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //暂存树的总个数
        int n = inorder.size();
        //对中序遍历的结果进行遍历，保存每个节点在中序遍历中的位置到哈希表中
        //根据节点值快速定位结点在中序遍历中的位置，可以很方便的得到左子树和右子树范围
        for (auto i = 0; i<n; i++){
            pos[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};