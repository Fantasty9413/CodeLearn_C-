// leetcode--107

# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(0), left(nullptr), right(nullptr){}
};


class Solution 
{
    public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> result;
        queue<TreeNode*> que;

        // root是否为空
        if(root==nullptr) return result;
        que.push(root);

        // 层序遍历
        while(!que.empty())
        {
            TreeNode* node = nullptr;
            int size = que.size();
            vector<int> orderresult;
            for(int i=0; i<size; i++)
            {
                // 取队列头节点作为当前节点
                node = que.front();
                que.pop();

                // 节点操作
                orderresult.push_back(node->val);
                if(node->left!=nullptr) que.push(node->left);
                if(node->right!=nullptr) que.push(node->right);
            }
            result.push_back(orderresult);
        }

        // result反转，返回结果
        reverse(result.begin(), result.end());
        return result;
    }
};