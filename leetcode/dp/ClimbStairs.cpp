// leetcode -- 70

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        // 判断输入
        if(n<=2)
        {
            return n;
        }

        // 创建dp数组       
        vector<int>dp(n+1);     // dp数组

        // 初始化
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        // 递归推导
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};