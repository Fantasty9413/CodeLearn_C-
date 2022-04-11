# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        // 记录s中字符出现次数
        for(char c: s)
        {
            int index = c - 'a';
            record[index]++;
        }

        // 减去t中字符出现次数
        for(char c: t)
        {
            int index = c - 'a';
            record[index]--;
        }

        // 查看hash数组是否全为0
        for(int x: record)
        {
            if(x!=0)
            {
                return false;
            }
        }

        return true;
    }
};