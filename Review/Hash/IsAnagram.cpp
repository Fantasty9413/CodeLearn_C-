// leetcode -- 242

# include <string>
# include <unordered_map>
using namespace std;

class Solution 
{
    public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false;

        unordered_map<char, int> chartable_s;
        unordered_map<char, int> chartable_t;

        // 统计s和t中各字符出现次数
        for(char c: s) chartable_s[c]++;
        for(char c: t) chartable_t[c]++;

        // 统计s和t中各字符出现次数是否相同
        for(auto itr=chartable_s.begin(); itr!=chartable_s.end(); itr++)
        {
            char c = itr->first;
            if(chartable_s[c]!=chartable_t[c]) return false;  // 出现不等时，直接返回false
        }
        return true;

        // ！要判断两个元素的各自的hash表是否相等，可以转换为遍历第一个元素时，hash表value值+；遍历第二个元素时，hash表value值-；最后看hash表中是否所有value为0。
    }
};