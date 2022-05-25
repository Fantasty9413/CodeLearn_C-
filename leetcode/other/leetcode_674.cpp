// leetcode -- 674

# include <vector>
# include <algorithm>
using namespace std;

class Solution 
{
    public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> increasingnums(len, 0);
        increasingnums[0] = 1;
        for(int i=1; i<len; i++)
        {
            if(nums[i]>nums[i-1]) increasingnums[i]=increasingnums[i-1]+1;  // 当前元素大于上一元素
            else increasingnums[i]=1;                                       // 当前元素小于等于上一元素
        }
        return *max_element(increasingnums.begin(), increasingnums.end());
    }
};