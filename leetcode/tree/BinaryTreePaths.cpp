// leetcode -- 257

# include <vector>
# include <string>
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
    private:
    vector<int> path;
    vector<vector<int>> paths;
    void backtracking(TreeNode* node)       // 回溯遍历寻找所有路径
    {
        path.push_back(node->val);          // push操作提前了
        // 确定终止条件--中
        if(node->left==nullptr && node->right==nullptr)
        {
            paths.push_back(path);
            return;
        }

        // 节点操作
        // 左节点
        // path.push_back(node->val);
        // backtracking(node->left);
        // path.pop_back();
        if(node->left!=nullptr)
        {
            backtracking(node->left);
            path.pop_back();                // 依然需要撤销操作
        }
        // 右节点
        // path.push_back(node->val);
        // backtracking(node->right);
        // path.pop_back();
        if(node->right!=nullptr)
        {
            backtracking(node->right);
            path.pop_back();
        }                
    }
    vector<string> resultconvert(vector<vector<int>> paths)
    {
        vector<string> result;
        for(auto path: paths)
        {
            string temp;
            temp += to_string(path[0]);
            for(int i=1; i<path.size(); i++)
            {
                temp += "->";
                temp += to_string(path[i]);
            }
            result.push_back(temp);
        }
        return result;
    }
    public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        path.clear();
        paths.clear();
        backtracking(root);
        return resultconvert(paths);
    }
};