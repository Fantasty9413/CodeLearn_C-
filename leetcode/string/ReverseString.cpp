// leetcode-344

# include <iostream>
# include <vector>
using namespace std;

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int slowindex = 0;
        int fastindex = s.size() - 1;
        while(slowindex < fastindex)
        {
            swap(s[slowindex++], s[fastindex--]);
        }
    }
};

int main()
{
    vector<char> s = {'a', 'b', 'v'};
    Solution solution;
    solution.reverseString(s);
    
    return 0;
}