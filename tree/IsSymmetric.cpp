// leetcode -- 101

# include <iostream>
# include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 深度优先遍历的递归法
// class Solution 
// {
//     private:
//     bool compare(TreeNode* left, TreeNode* right)
//     {
//         // 设定终止条件
//         if(left==nullptr && right==nullptr) return true;
//         else if(left==nullptr && right!=nullptr) return false;
//         else if(left!=nullptr && right==nullptr) return false;
//         else if(left->val != right->val) return false;

//         // 节点操作
//         bool outsidecmp = compare(left->left, right->right);
//         bool insidecmp = compare(left->right, right->left);
//         bool issame = outsidecmp&&insidecmp;
//         return issame;
//     }
//     public:
//     bool isSymmetric(TreeNode* root) 
//     {
//         if(root==nullptr) return true;
//         bool result = compare(root->left, root->right);
//         return result;
//     }
// };

// 层序遍历的迭代法
class Solution 
{
    public:
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*> que;
        if(root==nullptr) return false;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty())
        {
            // 取出需要操作的节点
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();

            // 终止条件
            if(left==nullptr && right==nullptr) continue;
            else if(left==nullptr && right!=nullptr) return false;
            else if(left!=nullptr && right==nullptr) return false;
            else if(left->val!=right->val) return false;

            // 节点操作 每次操作需要两个节点
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};