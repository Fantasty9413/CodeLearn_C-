// leetcode-541

# include <iostream>
# include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        for(int i=0; i<s.size(); i=i+2*k)
        {
            if(i+k<s.size())
            {
                reverse(s.begin()+i, s.begin()+i+k);
            }
            else
            {
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};

int main()
{
    string s = "abcdefghi";
    Solution solution;
    string ss = solution.reverseStr(s, 4);

    return 0;
}