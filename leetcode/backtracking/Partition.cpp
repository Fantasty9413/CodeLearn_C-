// leetcode -- 131

# include <string>
# include <vector>
using namespace std;

class Solution {
    private:
    vector<string> result;
    vector<vector<string>> results;
    void backtracking(string str, int startindex)
    {
        // 终止条件
        if(startindex >= str.size())
        {
            // 存放结果（单次的结果存进总结果中）
            results.push_back(result);
            return;
        }
        // 集合子集操作
        for(int i=startindex; i<str.size(); i++)
        {
            // 执行节点操作（如果节点操作需要判断，就用if-else-continue的结构）
            string substr = str.substr(startindex, i-startindex+1);
            if(isPalindrome(substr))
            {
                result.push_back(substr);
            }
            else
            {
                continue;
            }
            backtracking(str, i+1);
            result.pop_back();
        }
    }

    bool isPalindrome(string str)
    {
        int headindex = 0;
        int tailindex = str.size()-1;
        while(headindex <= tailindex)
        {
            if(str[headindex] != str[tailindex]) return false;
            headindex++;
            tailindex--;
        }
        return true;
    }

    public:
    vector<vector<string>> partition(string s) 
    {
        result.clear();
        results.clear();
        backtracking(s, 0);
        return results;
    }
};