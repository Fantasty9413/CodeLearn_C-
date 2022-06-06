// leetcode -- 509

# include <vector>
using namespace std;

class Solution 
{
    public:
    int fib(int n) 
    {
        // 考虑初始化的特殊情况
        if(n<=1) return n;
        // 正常情况 
        vector<int> dp(n+1, 0);  // dp数组创建
        for(int i=0; i<=1; i++) dp[i]=i;  // dp数组初始化
        for(int i=2; i<=n; i++) dp[i]=dp[i-1]+dp[i-2]; // dp数组递推
        return dp[n];  //！有n+1个数，最后元素的下标依旧是n
    }
};