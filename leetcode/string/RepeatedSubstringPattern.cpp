# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    void GetNext(int* next, const string &s)
    {
        // 初始化
        int j = 0;  // 前缀索引
        next[0] = 0;

        for(int i=1; i<s.size(); i++)
        {
            // 前后缀索引对应字符不同：回退
            while(j>0 && s[i]!=s[j])
            {
                j = next[j-1];
            }
            // 前后缀索引对应字符不同：索引+1
            if(s[i] == s[j])
            {
                j++;
            }
            // 更新next数组
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) 
    {
        int len_str = s.size();
        int next[len_str];
        GetNext(next, s);
        if(next[len_str-1]!=0 && len_str%(len_str - next[len_str-1])==0)
        {
            return true;
        }
        return false;
    }
};