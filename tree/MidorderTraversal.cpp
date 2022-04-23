# include <iostream>
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
    void Traversal(TreeNode* cur, vector<int>& vec)
    {
        // 2.确定终止条件
        if(cur == nullptr) return;
        // 3.确定单层遍历逻辑
        Traversal(cur->left, vec);
        vec.push_back(cur->val);
        Traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        Traversal(root, result);
        return result;
    }
};