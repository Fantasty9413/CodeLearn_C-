// leetcode--494

# include <vector>
# include <numeric>
# include <cmath>
using namespace std;

class Solution 
{
    public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        // 求解positive，转换为01背包问题
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum<abs(target)) return 0;            // nums的总和小于target
        if((sum+target)%2==1) return 0;
        int positive = (sum+target) / 2;

        // 01背包问题
        // 创建dp数组
        vector<vector<int>> dp(nums.size()+1, vector<int>(positive+1, 0)); 
        // dp数组初始化
        dp[0][0] = 1;
        // for(int i=1; i<nums.size(); i++)
        // {
        //     if(nums[i]==0) dp[i][0]++;
        // }
        // 递推
        for(int i=1; i<=nums.size(); i++)
        {
            for(int j=0; j<=positive; j++)
            {
                if(j-nums[i-1]>=0) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[nums.size()][positive];
    }
};