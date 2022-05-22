// ,eetcode--77

# include <vector>
using namespace std;

class Solution 
{
    private:
    vector<int> result;
    vector<vector<int>> results;
    void backtracking(int n, int k, int startindex)
    {
        // 终止条件
        if(result.size()==k)
        {
            results.push_back(result);
            return;
        }
        // 节点操作--在本层集合元素中进行选择
        for(int i=startindex; i<=n; i++)
        {
            // 节点操作
            result.push_back(i);
            backtracking(n, k, i+1);
            result.pop_back();
        }
    }
    public:
    vector<vector<int>> combine(int n, int k) 
    {
        result.clear();
        results.clear();
        backtracking(n, k, 1);
        return results;
    }
};