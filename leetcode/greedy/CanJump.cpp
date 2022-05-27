// leetcode -- 55

# include <vector>
using namespace std;

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int cover = 0;
        for(int i=0; i<=cover; i++)
        {
            cover = max(cover, i+nums[i]);
            if(cover>=nums.size()-1) return true;
        }
        return false;
    }
};