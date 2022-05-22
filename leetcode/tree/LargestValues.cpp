// leetcode -- 515

# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution 
{
    public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> results;    // 存放结果
        if(root==nullptr) return results;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();  // 当前层中节点的个数
            TreeNode* node = nullptr;
            vector<int> nums;
            for(int i=0; i<size; i++)
            {
                // 取节点
                node = que.front();
                que.pop();
                // 节点操作
                nums.push_back(node->val);  // 取值
                // 节点入队列
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            int max_value = *max_element(nums.begin(), nums.end());
            results.push_back(max_value);
        }
        
        return results;
    }
};