# include <iostream>
# include <stack>
# include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        vector<int> result;
        if(root != nullptr) st.push(root);
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            if(cur != nullptr)     // 入栈
            {
                st.pop();
                if(cur->right != nullptr) st.push(cur->right);      // 子节点要非空才能入栈
                st.push(cur);
                st.push(nullptr);
                if(cur->left != nullptr) st.push(cur->left);
            }
            else    // 出栈
            {
                st.pop();
                TreeNode* cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }
};
