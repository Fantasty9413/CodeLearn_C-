// leetcode -- 216

# include <vector>
using namespace std;

class Solution 
{
    private:
    vector<int> result;     // 存放单词组合的结果
    vector<vector<int>> results;  // 存放所有总结果
    void backtracking(int n, int k, int sum, int startindex)
    {
        // 终止条件
        if(result.size()==k)
        {
            if(sum==n) results.push_back(result);
            return;
        }
        // 集合元素选择
        for(int i=startindex; i<=9&&sum+i<=n; i++)
        {
            // 元素操作
            sum += i;
            result.push_back(i);
            // 递归
            backtracking(n, k, sum, i+1);
            // 回溯-撤销操作
            result.pop_back();
            sum -= i;
        }
    }

    public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        result.clear();
        results.clear();
        int sum = 0;
        backtracking(n, k, sum, 1);
        return results;
    }
};