// leetcode -- 47

# include <vector>
# include <algorithm>
using namespace std;

class Solution 
{
    private:
    vector<int> result;             // 存放单次结果
    vector<vector<int>> results;    // 存放总的结果
    void backtracking(vector<int> nums, vector<bool> used)
    {
        // 终止条件
        if(result.size()==nums.size())
        {
            results.push_back(result);
            return;
        }

        // 选择集合中的元素
        for(int i=0; i<nums.size(); i++)
        {
            // 去重
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) continue;
            // 当前元素使用过，跳过选择下一元素
            if(used[i]==true) continue;
            // 当前元素没使用过，进行元素操作
            used[i] = true;
            result.push_back(nums[i]);
            backtracking(nums, used);
            result.pop_back();
            used[i] = false;
        }
    }
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        result.clear();
        results.clear();
        sort(nums.begin(), nums.end());     // 排序
        vector<bool> used(nums.size(), false);  // 构造used数组
        backtracking(nums, used);
        return results;
    }
};