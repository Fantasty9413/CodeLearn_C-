// leetcode-209

# include <vector>
using namespace std;

# define MAX 100000

class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int slowindex = 0;
        int fastindex = 0;
        int sum = 0;        // 窗口数组和
        int resutl = MAX;    // 
        int winlen = 0;     // 窗口长度
        while (fastindex < nums.size())
        {
            sum = sum + nums[fastindex];
            while(sum >= target)                    // 可能慢指针向前移动几次才能使得窗口和小于目标值
            {
                winlen = fastindex - slowindex + 1; // 获取长度
                resutl = winlen<resutl ? winlen : resutl;
                sum = sum - nums[slowindex];    // 移动慢指针
                slowindex++;
            }
            fastindex++;
        }
        resutl = resutl!=MAX ? resutl : 0;
        return resutl;
    }
};