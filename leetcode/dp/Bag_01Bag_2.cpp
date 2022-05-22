# include <vector>
# include <iostream>
using namespace std;

class Solution
{
    public:
    int MaxWeight(vector<int> weight, vector<int> value, int bagweight)
    {
        // 定义dp数组
        vector<int> dp(bagweight+1, 0);

        // 初始化dp数组
        for(int j=0; j<=bagweight; j++)
        {
            if(j<weight[0]) dp[j]=0;        // 第0个物品放不进背包
            if(j>=weight[0]) dp[j]=value[0];// 第0个物品放得进背包
        }

        // 递归推导
        for(int i=0; i<weight.size(); i++)
        {
            for(int j=bagweight; j>=weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        return dp[bagweight];
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