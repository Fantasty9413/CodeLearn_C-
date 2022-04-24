// leetcode -- 104

# include <algorithm>
# include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 深度优先遍历--递归法
// class Solution 
// {
//     private:
//     int getdepth(TreeNode* node)
//     {
//         // 确定终止条件
//         if(node==nullptr) return 0;
//         // 递归操作
//         int leftdepth = getdepth(node->left);
//         int rightdepth = getdepth(node->right);
//         int depth = 1 + std::max(leftdepth, rightdepth);
//         return depth;
//     }
//     public:
//     int maxDepth(TreeNode* root) 
//     {
//         return getdepth(root);
//     }
// };

// 广度优先遍历--迭代法
class Solution 
{
    public:
    int maxDepth(TreeNode* root) 
    {
        if(root==nullptr) return 0;
        std::queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left!=nullptr) que.push(node->left);
                if(node->right!=nullptr) que.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};