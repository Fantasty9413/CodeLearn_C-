// leetcode -- 122

# include <vector>
# include <iostream>
using namespace std;

class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> profits(prices.size(), 0);  // 利润序列
        for(int i=1; i<prices.size(); i++) profits[i]=prices[i]-prices[i-1];
        int profit = 0;
        for(int x: profits) if(x>0) profit+=x;
        return profit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;
    int profit = s.maxProfit(prices);
    cout << "profit: " << profit;

    return 0;
}