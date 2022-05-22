# include <vector>
# include <iostream>
using namespace std;

class Solution
{
    public:
    int MaxWeight(vector<int> weight, vector<int> value, int bagweight)
    {
        // 定义dp数组
        vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));

        // 初始化dp数组
        for(int i=0; i<weight.size(); i++) dp[i][0] = 0;
        for(int j=0; j<=bagweight; j++)
        {
            if(j<weight[0]) dp[0][j] = 0;
            if(j>=weight[0]) dp[0][j] = value[0];
        }

        // 递推公式
        // 先物品，后背包
        for(int i=1; i<weight.size(); i++)
        {
            for(int j=0; j<=bagweight; j++)
            {
                if(j<weight[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
        return dp[weight.size()-1][bagweight];
    }
};

int main()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    Solution solution;
    int maxweight =  solution.MaxWeight(weight, value, bagweight);
    cout << maxweight;

    return 0;   
}