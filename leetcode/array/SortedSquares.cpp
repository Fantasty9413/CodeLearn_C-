// leetcode-977
# include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int slowindex = 0;
        int fastindex = nums.size() - 1;
        vector<int> result(nums.size(), 0); // result nums
        int resultindex = result.size() - 1;
        while(slowindex <= fastindex)   // resultindex >= 0
        {
            int var1 = nums[slowindex] * nums[slowindex];
            int var2 = nums[fastindex] * nums[fastindex];
            if(var1 > var2)
            {
                result[resultindex] = var1;
                slowindex++;
            }
            else
            {
                result[resultindex] = var2;
                fastindex--;
            }
            resultindex--;
        }

        return result;
    }
};