// leetcode-27
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void _swap(int &var1, int &var2)
    {
        var1 = var1 + var2;
        var2 = var1 - var2;
        var1 = var1 - var2;
    }

    int removeElement(vector<int>& nums, int val) 
    {
        int slow = 0;
        int fast = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != val)// 比较是否等于目标值
            {
                nums[slow] = nums[fast];
                fast = fast + 1;
                slow = slow + 1;
            }      
            else
            {
                fast = fast + 1;
            }
        }
        return slow;
    }
};
