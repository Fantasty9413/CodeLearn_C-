// leetcode -- 637

# include <vector>
# include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> results;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();      // 队列中的节点个数（当前层元素）
            TreeNode* node = nullptr;   // 当前操作节点
            long sum = 0;               // 层元素和
            for(int i=0; i<size; i++)
            {
                // 取队列头节点
                node = que.front();
                que.pop();
                // 节点操作
                sum += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            double avg = (double)sum / size;
            results.push_back(avg);
        }
        return results;
    }
};