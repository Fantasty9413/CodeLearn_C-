// leetcode -- 416

# include <vector>
# include <numeric>
using namespace std;

class Solution 
{
    public:
    bool canPartition(vector<int>& nums) 
    {
        // 转换为0-1背包问题
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1) return false;  // 无法整数二分
        int target = sum/2;

        // 转换为0-1背包问题
        int bagweight = target;
        // 创建dp数组
        vector<vector<int>> dp(nums.size(), vector(bagweight+1, 0));
        // 初始化dp数组
        for(int i=0; i<nums.size(); i++) dp[i][0]=0;
        for(int j=0; j<=bagweight; j++)
        {
            if(j>=nums[0]) dp[0][j]=nums[0];
            else dp[0][j]=0;
        }
        // dp数组递推
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j<=bagweight; j++)
            {
                if(j-nums[i]>=0) dp[i][j]=max(dp[i-1][j-nums[i]]+nums[i],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }

        // 求解结果
        if(dp[nums.size()-1][bagweight]==target) return true;
        else return false; 
    }
};