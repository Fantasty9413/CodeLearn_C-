// leetcode -- 455

# include <vector>
# include <algorithm>
using namespace std;

class Solution 
{
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());       // 胃口值
        sort(s.begin(), s.end());       // 饼干值

        // 双指针
        int result = 0;
        int index_g = g.size()-1;
        int index_s = s.size()-1;
        while(index_g>=0 && index_s>=0)
        {
            if(s[index_s]>=g[index_g])      // 当前饼干能满足当前胃口
            {
                index_s--;
                index_g--;
                result++;
            }
            else                            // 当前饼干不能满足当前胃口
            {
                index_g--;
            }
        }
        return result;
    }
};