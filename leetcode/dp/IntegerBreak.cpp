// leetcode -- 343

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) 
    {
        // 
        vector<int> dp(n+1, 0);
        // 初始化
        dp[2] = 1;
        for(int i=3; i<=n; i++)
        {
            // dp递推
            for(int j=1; j<i; j++)
            {
                int temp = max(j*(i-j), j*dp[i-j]); // 当前一次的最大乘积值
                dp[i] = max(dp[i], temp);
            }
        }
        return dp[n];
    }
};