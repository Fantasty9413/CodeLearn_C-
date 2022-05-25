// leetcode -- 238

# include <vector>
using namespace std;

class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> L(len, 1);  // 存放从左到右的乘积
        vector<int> R(len, 1);  // 存放从右到左的乘积
        for(int i=1; i<len; i++) L[i]=L[i-1]*nums[i-1];
        for(int j=len-2; j>=0; j--) R[j]=R[j+1]*nums[j+1];
        vector<int> answer(len, 0);
        for(int i=0; i<len; i++) answer[i]=L[i]*R[i];
        return answer;
    }
};