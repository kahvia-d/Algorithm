//
// Created by Kahiva on 2023/10/27.
//
//https://www.acwing.com/problem/content/3789/
//二叉排序树

#include <iostream>

using namespace std;

const int INF = 1e8;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value):val(value),left(NULL),right(NULL){}
}*root;


void insert(TreeNode* &root, int x){
    //如果这是个空树（或者空子树），则创建树结点，保存这个元素.
    //ps：由于对root指针变量采取的引用，因此直接修改root就是同步修改父节点的left或者right指针值。
    if(root == NULL) root = new TreeNode(x);
    else if(x < root->val ) insert(root->left, x);
    else insert(root->right, x);
}

void remo(TreeNode* &root, int x){
    if (x < root->val) remo(root->left, x);
    else if(x > root->val) remo(root->right, x);
    else{
        //如果待删除的结点是叶子结点，直接删除就好
        if (!root->left && !root->right){
            auto p = root;
            root = NULL;
            delete p;
        }
            //如果待删除结点有一个儿子，删除结点后让儿子取而代之即可。
        else if(!root->left || !root->right){
            auto temp = root;
            root = root->left ? root->left : root->right;
            delete temp;
        }
            //如果待删除结点p有两个儿子，则寻找做左子树中最大的结点c，将其值赋给待删除结点p，转而删除c即可。
        else{
            //寻到左子树最大值
            auto expolorer = root->left;
            int lm = expolorer->val;
            while((expolorer = expolorer->right)!= NULL) lm = expolorer->val;
            //令它取其父而代之
            root->val = lm;
            remo(root->left, lm);
        }
    }
}


int find_pre(TreeNode* root, int x){
    //如果是空子树（NULL），则没有值可言，为防止段错误，返回自定义的值。
    //ps：此时父节点的值已经是小于x的最大值了，我们为空结点返回负无穷的数，方便max函数取较大值（父节点）。
    if(root == NULL) return -INF;
    if (x <= root->val) return find_pre(root->left, x);
    return max(root->val, find_pre(root->right, x));
}

int find_rear(TreeNode* root, int x){
    //类似同上。
    if(root == NULL) return INF;
    if (x >= root->val) return find_rear(root->right, x);
    return min(root->val, find_rear(root->left, x));
}

int main(){
    int n;
    cin>>n;
    int opt, x;
    for (auto i = 0; i< n; i++){
        cin>>opt>>x;
        if(opt == 1) insert(root, x);
        if(opt == 2) remo(root, x);
        if(opt == 3) cout<<find_pre(root, x)<<endl;
        if(opt == 4) cout<<find_rear(root, x)<<endl;
    }

    return 0;
}