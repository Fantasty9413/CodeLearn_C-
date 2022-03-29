// 剑指offer-05

# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) 
    {
        
        int len = s.size();
        int slowindex = 0;
        int fastindex = 0;
        int count = 0;      // 空格个数

        // 寻找空格个数
        while(slowindex < len)
        {
            (s[slowindex]==' ') ? count++ : count+=0 ;
            slowindex++;
        }        
        // 扩充字符串
        s.resize(len + 2*count);
        int newlen = s.size();

        // 替换空格
        fastindex = newlen - 1;
        slowindex = len - 1;
        while(count > 0)
        {
            if(s[slowindex] != ' ')
            {
                s[fastindex] = s[slowindex];
                slowindex--;
                fastindex--;
            }
            else
            {
                s[fastindex] = '0';
                s[fastindex-1] = '2';
                s[fastindex-2] = '%';
                slowindex--;
                fastindex = fastindex - 3;
                count--;
            }
        }

        return s;
    }
};