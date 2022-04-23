# include <vector>
# include <algorithm>
using namespace std;

class Solution 
{
    private:
    vector<vector<int>> results;
    vector<int> result;
    void backtracking(vector<int> nums, int target, int sum, int startindex)
    {
        // 确定终止条件
        if(sum >= target)
        {
            if(sum == target) results.push_back(result);
            return;
        }
        // 遍历操作
        for(int i=startindex; i<nums.size() && sum+nums[i]<=target; i++)
        {
            // 节点操作
            result.push_back(nums[i]);
            sum += nums[i];
            backtracking(nums, target, sum, i);
            result.pop_back();
            sum -= nums[i];
        }
    }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        results.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());     // 若要剪枝 要先排序
        backtracking(candidates, target, 0, 0);
        return results;
    }
};