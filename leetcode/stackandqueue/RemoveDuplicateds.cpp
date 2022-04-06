# include <iostream>
# include <string>
# include <stack>
# include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        // 栈顶字符与当前字符相比较
        // 相同：栈顶出栈
        // 不同：字符入栈
        stack<char> sta;

        for(char c: s)
        {
            if(!sta.empty() && sta.top()==c)
            {
                sta.pop();
            }
            else
            {
                sta.push(c);
            }
        }

        // 字符全部出栈并反转获取最终字符串
        string result = "";
        while(!sta.empty())
        {
            result = result + sta.top();
            sta.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};