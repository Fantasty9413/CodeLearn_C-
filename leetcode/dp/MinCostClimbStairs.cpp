// leetcode -- 746

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        // 判断输入
        int n = cost.size();
        if(n == 1)
        {
            return cost[0];
        }
        else if(n == 2)
        {
            return min(cost[0], cost[1]);
        }

        // 创建dp数组
        vector<int> dp(n);

        // 初始化
        dp[0] = cost[0];
        dp[1] = cost[1];

        // 递归推导
        for(int i=2; i<n; i++)
        {
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }

        return min(dp[n-2], dp[n-1]);
    }
};