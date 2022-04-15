# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int, int> umap;
        // 记录前两数组的数字和
        for(int x1: nums1)
        {
            for(int x2: nums2)
            {
                umap[x1+x2]++;
                // umap.at(x1+x2)++;
            }
        }

        int count = 0;
        // 用后两数组的数字和搜索
        for(int x3: nums3)
        {
            for(int x4: nums4)
            {
                // auto itr = umap.find(0-(x3+x4));
                // if(itr!=umap.end())
                // {
                //     count += itr->second;
                // }
                if(umap.find(0-(x3+x4)) != umap.end())
                {
                    count += umap[0-(x3+x4)];
                }
            }
        } 
        return count;
    }
};