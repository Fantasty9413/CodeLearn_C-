// leetcode -- 300

# include <vector>
# include <algorithm>
using namespace std;

class Solution 
{
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size()==1) return 1;
        int len = nums.size();

        // 创建dp数组
        vector<int> dp(len, 0);

        // 初始化dp数组
        dp[0] = 1;

        // 推导dp数组
        for(int i=1; i<len; i++)
        {
            int max_pre_len = 0;
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j]) max_pre_len=max(max_pre_len,dp[j]);
            }
            dp[i] = max_pre_len + 1;
        }

        // 返回结果
        return *max_element(dp.begin(), dp.end());
    }
};