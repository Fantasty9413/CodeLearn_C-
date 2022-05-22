// leetcode -- 334

# include <vector>
using namespace std;

class Solution 
{
    public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if(nums.size()<3) return false;
        int first = nums[0];
        int second = __INT_FAST32_MAX__;
        for(int i=1; i<nums.size(); i++)
        {
            int num = nums[i];
            if(num>second) return true;
            if(num>first) second=num;
            else first=num;
        }
        return false;
    }
};