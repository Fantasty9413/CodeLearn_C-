// leetcode -- 144
# include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void Traversal(TreeNode* cur, vector<int>& vec)     // 1.确定递归函数的参数和返回值
    {
        // 2.确定返回条件
        if(cur == nullptr) return;
        // 3.确定单层逻辑
        vec.push_back(cur->val);
        Traversal(cur->left, vec);
        Traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        Traversal(root, result);
        return result;
    }
};