// leetcode -- 704

# include <vector>
using namespace std;

class Solution 
{
    public:
    int search(vector<int>& nums, int target) 
    {
        // 区间左闭右闭
        // 左右边界确定中间下标，中间下标值与目标值相比，然后更新左右边界值
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right)
        {
            // 不断缩小左右区间以定位目标数
            mid = (left+right) / 2;
            if(nums[mid]>target) right=mid-1;  // ！因为mid处元素不等于target，所以更新时一定要更新到mid两边
            if(nums[mid]<target) left=mid+1;
            if(nums[mid]==target) return mid;
        }
        // 未找到目标数时，自动退出循环
        return -1;
    }
};