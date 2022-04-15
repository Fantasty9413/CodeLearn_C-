// leetcode -- 383

# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // 分解杂志串内容
        vector<int> magazinecharnums(26, 0);
        for(char c: magazine)
        {
            int addressindex = c - 'a';
            magazinecharnums[addressindex]++;
        }

        // 赎金串对比
        for(char c: ransomNote)
        {
            int addressindex = c - 'a';
            magazinecharnums[addressindex]--;
            if(magazinecharnums[addressindex] < 0)
            {
                return false;
            }
        }

        // 返回结果
        return true;
    }
};