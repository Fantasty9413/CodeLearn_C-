// leetcode -- 77

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
        // 集合操作
        for(int i=startindex; i<=n+1-k+result.size(); i++)  //！剪枝操作，保证剩下的数的个数能够选满
        {
            // 层元素操作
            result.push_back(i);
            // 递归
            backtracking(n, k, i+1);
            // 撤销操作
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