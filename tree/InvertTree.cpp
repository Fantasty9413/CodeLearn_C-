// leetcode -- 226

# include <vector>
# include <stack>
# include <queue>
// # include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 深度遍历--递归法
// class Solution 
// {
//     private:
//     void traversal(TreeNode* node)
//     {
//         // 确定终止条件
//         if(node == nullptr) return;
//         // 节点操作
//         swap(node->left, node->right);
//         traversal(node->left);
//         traversal(node->right);
//     }
//     public:
//     TreeNode* invertTree(TreeNode* root) 
//     {
//         traversal(root);
//         return root;
//     }
// };

// 深度遍历--迭代法
// class Solution 
// {
//     public:
//     TreeNode* invertTree(TreeNode* root) 
//     {
//         stack<TreeNode*> st;
//         if(root!=nullptr) st.push(root);
//         while(!st.empty())
//         {
//             TreeNode* node = st.top();
//             if(node!=nullptr)
//             {
//                 st.pop();
//                 if(node->right) st.push(node->right);
//                 if(node->left) st.push(node->left);
//                 st.push(node);
//                 st.push(nullptr);

//             }
//             else
//             {
//                 st.pop();
//                 node = st.top();
//                 st.pop();
//                 swap(node->left, node->right);
//             }
//         }
//         return root;
//     }
// };

// 广度遍历
class Solution 
{
    public:
    TreeNode* invertTree(TreeNode* root) 
    {
        queue<TreeNode*> que;
        if(root!=nullptr) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
};