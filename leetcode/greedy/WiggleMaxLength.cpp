// leetcode -- 376

# include <vector>
using namespace std;

class Solution 
{
    public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int PreDiff = 0;
        int CurDiff = 0;
        int result = 1;
        for(int i=0; i<nums.size()-1; i++)
        {
            CurDiff = nums[i+1] - nums[i];  // 更新curdiff
            if((PreDiff>=0 && CurDiff<0) || (PreDiff<=0 && CurDiff>0))
            {
                PreDiff = CurDiff;
                result++;
            }
        }
        return result;
    }
};