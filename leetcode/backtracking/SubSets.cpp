# include <vector>
using namespace std;

class Solution 
{
    vector<int> result;
    vector<vector<int>> results;
    void backtracking(int startindex, vector<int> nums)
    {
        results.push_back(result);
        if(result.size()==nums.size()) return;

        for(int i=startindex; i<nums.size(); i++)
        {
            result.push_back(nums[i]);
            backtracking(i+1, nums);
            result.pop_back();
        }
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        result.clear();
        results.clear();
        backtracking(0, nums);
        return results;
    }
};