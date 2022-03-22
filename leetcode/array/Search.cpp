// leetcode-704
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size();
        int mid = 0;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)      // 区间往左收缩
            {
                right = mid;
            }
            else                        // 区间往右收缩 
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};