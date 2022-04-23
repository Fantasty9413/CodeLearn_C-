# include <vector>
# include <stack>
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
    vector<int> postorderTraversal(TreeNode* root)      // 左右中
    {
        stack<TreeNode*> st;
        vector<int> result;
        if(root != nullptr) st.push(root);
        while(!st.empty())
        {
            // 判断栈顶是否为空，为标记节点
            TreeNode* node = st.top();
            if(node != nullptr)
            {
                st.pop();
                // 中
                st.push(node);
                st.push(nullptr);
                // 右
                if(node->right) st.push(node->right);
                // 左
                if(node->left) st.push(node->left);                
            }
            else
            {
                st.pop();
                TreeNode* node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};