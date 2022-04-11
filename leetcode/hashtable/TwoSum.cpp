// leetcode -- 1

# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> keymap;     // key:数字值 value:下标
        vector<int> result;
        for(int i=0; i<nums.size(); i++)
        {
            // 判断target-nums[i]在map中否
            // 不在：入map
            // 在：直接返回两个的下标
            unordered_map<int, int>::iterator itr = keymap.find(target-nums[i]);
            if(itr==keymap.end())
            {
                keymap.emplace(make_pair(nums[i], i));      // 入map原数
            }
            else
            {
                result.push_back(itr->second);
                result.push_back(i);
            }
        }
        return result;
    }
};