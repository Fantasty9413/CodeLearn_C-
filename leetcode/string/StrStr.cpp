# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    void GetNext(int *next, const string &s)
    {
        // 初始化
        next[0] = 0;
        int j = 0;

        for(int i=1; i<s.size(); i++)
        {
            // 前后缀不相等处理：回退索引位置
            while(j>0 && s[i]!=s[j])
            {
                j = next[j-1];
            }
            // 前后缀相等处理：索引+1
            if(s[i] == s[j])
            {
                j++;
            }
            // 更新next数组
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
        {
            return 0;
        }

        // 初始化
        int j = 0;
        int next[needle.size()];
        GetNext(next, needle);

        for(int i=0; i<haystack.size(); i++)
        {
            // 字符比较不同时：索引回退
            while(j>0 && haystack[i]!=needle[j])
            {
                j = next[j-1];
            }

            // 字符比较相同时：索引增加
            if(haystack[i] == needle[j])
            {
                j++;
            }

            // 判断索引是否到needle尾巴
            if(j == needle.size())
            {
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
};