// leetcode -- 491

# include <vector>
# include <unordered_set>
using namespace std;

class Solution 
{
    private:
    vector<int> result;                 // 存放单次结果
    vector<vector<int>> results;        // 存放所有结果
    void backtracking(vector<int> nums, int startindex)
    {
        // 存放结果
        if(result.size()>=2) results.push_back(result);

        unordered_set<int> used;        // 本层元素去重
        // 本层集合中的元素选择
        for(int i=startindex; i<nums.size(); i++)
        {
            // 去重剪枝
            if(!result.empty() && nums[i]<result.back()) continue;
            if(used.count(nums[i])!=0) continue;
            used.insert(nums[i]);  // 放入used集合，标记为使用过
            result.push_back(nums[i]);
            backtracking(nums, i+1);
            result.pop_back();
        }
    }
    public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        result.clear();
        results.clear();
        backtracking(nums, 0);
        return results;
    }
};