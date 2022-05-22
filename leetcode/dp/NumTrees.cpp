// leetcode -- 96

# include <iostream>
# include <vector>
using namespace std;

class Solution 
{   
    public:
    int numTrees(int n) 
    {
        if(n==1) return 1;
        // n>=2
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            // 递归求解dp[i]
            for(int j=0; j<=i-1; j++)
            {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};