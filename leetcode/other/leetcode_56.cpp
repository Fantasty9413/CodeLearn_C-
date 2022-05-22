// leetcode -- 56

# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // 排序intervals
        sort(intervals.begin(), intervals.end());

        //
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            // 不需要合并，直接放入结果
            if(merged.back()[1]<L) merged.push_back({L, R});
            // 需要合并，
            merged.back()[1] = max(merged.back()[1], R);  // 选当前的end和下一组的end中大的作为end
        }

        return merged;
    }

};

int main()
{
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2, 6};
    vector<vector<int>> vs = {v1, v2};
    Solution s;
    auto results = s.merge(vs);

    return 0;
}