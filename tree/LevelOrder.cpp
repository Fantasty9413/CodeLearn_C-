// leetcode -- 102

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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;     // 用来存结果
        queue<TreeNode*> que;                  // 用来过数据
        if(root != nullptr) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;                // 用于存一层的数据
            for(int i=0; i<size; i++)
            {
                // 出队列头元素
                TreeNode* temp = que.front();
                que.pop();
                // 记录节点的值
                vec.push_back(temp->val);
                // 进队列尾元素
                if(temp->left != nullptr) que.push(temp->left);      // 不为空才进队列
                if(temp->right != nullptr) que.push(temp->right);     // 
            }
            result.push_back(vec);
        }
        return result;
    }
};