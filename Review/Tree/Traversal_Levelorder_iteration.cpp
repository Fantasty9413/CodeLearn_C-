// leetcode -- 102

# include <vector>
# include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution 
{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> results;
        if(root==nullptr) return results;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();    // 当前层的节点个数
            TreeNode* node = nullptr; // 操作节点
            vector<int> result;       // 单层元素
            for(int i=0; i<size; i++)
            {
                // 取操作节点
                node = que.front();
                que.pop();
                // 存值
                result.push_back(node->val);
                // 放子节点入队列
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            results.push_back(result);
        }
        return results;
    }
};
