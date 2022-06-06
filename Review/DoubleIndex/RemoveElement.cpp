// leetcode -- 27

# include <vector>
using namespace std;

class Solution 
{
    public:
    int removeElement(vector<int>& nums, int val) 
    {
        // 双指针法，将所有等于val的值移动到最后去
        // 左指针元素不等于val时候，左指针后移，右指针不动
        // 左指针元素等于val时候，右指针前移到不为val的元素位置，左右指针元素互换，左指针后移
        int left = 0;
        int right = nums.size()-1;
        while(right>=0 && nums[right]==val) right--;  //！在循环前先将right定位至不等于val的位置，要注意right更新时的范围要>=0
        while(left<right)
        {
            if(nums[left]!=val) left++;
            else
            {
                swap(nums[left], nums[right]);
                left++;
                while(nums[right]==val) right--;  //！由于right更新过程可能导致right<left，因此先交换，再更新right
            }
        }
        return right+1;  //！right最终指向倒数第一个不为val的数的下标，因此可以利用right判断非val值数组的长度
    }
};