// leetcode -- 53

# include <vector>
# include <algorithm>
using namespace std;

// // 贪心--双指针
// class Solution 
// {
//     public:
//     int maxSubArray(vector<int>& nums) 
//     {
//         int result = -__INT32_MAX__;
//         int sum = 0;
//         for(int i=0; i<nums.size(); i++)
//         {
//             // 双指针区间更新：慢指针不动，快指针前进
//             sum = sum + nums[i];
//             result = max(sum, result);
//             // 双指针区间更新：慢指针移动至快指针位置前方
//             if(sum<0) sum=0;
//         }
//         return result;
//     }
// };

// 动规
class Solution
{
    public:
    int maxSubArray(vector<int>& nums) 
    {
        // dp数组创建
        vector<int> dp(nums.size(), 0);  // 以i元素为结尾的最大连续和子数组的和
        // dp数组初始化
        dp[0] = nums[0];
        // dp数组更新
        for(int i=1; i<nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};