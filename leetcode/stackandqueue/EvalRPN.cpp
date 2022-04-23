# include <iostream>
# include <string>
# include <vector>
# include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 创建栈来存储运算数字
        stack<int> sta;
        
        for(string s: tokens)
        {
            // 判断是不是运算符
            // yes: 栈顶两元素进行运算，结果入栈
            // no：元素入栈
            if(s=="+" || s=="-" || s=="*" || s=="/")
            {
                int num1 = sta.top();
                sta.pop();
                int num2 = sta.top();
                sta.pop();
                int result;
                if(s=="+") result = num1 + num2;
                if(s=="-") result = num2 - num1;        // 减数与被减数的关系
                if(s=="*") result = num1 * num2;
                if(s=="/") result = num2 / num1;        // 除数与被除数的关系
                sta.push(result);
            }
            else
            {
                sta.push(stoi(s));
            }
        }
        return sta.top();
    }
};