
# include <vector>
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
private:
    vector<int> vec;
    void traversal(TreeNode* node)
    {
        // 终止条件
        if(node==nullptr) return;
        //
        vec.push_back(node->val);// 中
        traversal(node->left);   // 左
        traversal(node->right);  // 右
    }
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vec.clear();
        traversal(root);
        return vec;
    }
};
