# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());

        int index1 = 0;
        int index2 = index1+1;
        int index3 = nums.size()-1;
        for(; index1<nums.size(); index1++)
        {
            if(index1>0 && nums[index1] == nums[index1-1])
            {
                continue;
            }
            index2 = index1 + 1;
            index3 = nums.size()-1;
            while(index2<index3)
            {
                int sum = nums[index1] + nums[index2] + nums[index3];
                if(sum>0)       // 和大于0
                {
                    index3--;
                    while(index2<index3 && nums[index3] == nums[index3+1]){index3--;}
                }
                else if(sum<0)  // 和小于0
                {
                    index2++;
                    while(index2<index3 && nums[index2] == nums[index2-1]){index2++;}
                }
                else            // 和等于0
                {
                    result.push_back(vector<int>{nums[index1], nums[index2], nums[index3]});
                    index2++;
                    index3--;
                    while(index2<index3 && nums[index2] == nums[index2-1]){index2++;}
                    while(index2<index3 && nums[index3] == nums[index3+1]){index3--;}
                }
            }
        }
        return result;
    }
};