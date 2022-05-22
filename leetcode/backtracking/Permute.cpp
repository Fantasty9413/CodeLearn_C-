// leetcode -- 46

# include <vector>
using namespace std;

class Solution 
{
    private:
    vector<int> result;
    vector<vector<int>> results;
    void backtracking(vector<int>& nums, vector<bool> used)
    {
        // 终止条件
        if(result.size()==nums.size())
        {
            results.push_back(result);
            return;
        }
        // 集合元素选择
        for(int i=0; i<nums.size(); i++)
        {
            // 元素操作
            if(used[i]==true) continue;
            result.push_back(nums[i]);
            used[i] = true;
            // 递归
            backtracking(nums, used);
            // 回溯-撤销操作
            used[i] = false;
            result.pop_back();
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        result.clear();
        results.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return results;
    }
};