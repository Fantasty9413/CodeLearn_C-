// leetcode-349

# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;

        // 利用set对num1元素去重
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());   // 移动构造函数
        
        // 检查num2中元素是否再num1set中出现
        for(int x: nums2)
        {
            if(nums1_set.find(x) != nums1_set.end())         // 元素出现
            {
                result.insert(x);
            }
        }
        // 返回结果
        return vector<int> (result.begin(), result.end());
    }
};

