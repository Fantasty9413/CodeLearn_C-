# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <stack>
using namespace std;

// class Solution 
// {
//     private:
//     vector<string> results;     // 存所有结果
//     string result;
//     void backtracking(string str, int n, int startindex)
//     {
//         // 终止条件
//         if(result.size()==str.size()-n) results.push_back(result);
//         // 递归
//         for(int i=startindex; i<str.size(); i++)
//         {
//             // 节点操作
//             result.push_back(str[i]);
//             backtracking(str, n, i+1);
//             result.pop_back();
//         }
//     }
//     public:
//     string removeKdigits(string num, int k) 
//     {
//         result.clear();
//         results.clear();
//         backtracking(num, k, 0);

//         int minvalue = INT32_MAX;
//         for(string str: results)
//         {
//             int value = minvalue;
//             str=="" ? value=0 : value=stoi(str);
//             minvalue = min(minvalue, value);
//         }
//         return to_string(minvalue);
//     }
// };

// 单调栈

class Solution 
{
    public:
    string removeKdigits(string num, int k) 
    {
        vector<char> stk;
        // 单调栈操作--删除部分元素使得序列递增
        for(int i=0; i<num.size(); i++)
        {
            while(stk.size()>0 && stk.back()>num[i] && k>0)
            {
                // 进一次循环 删一个数字
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }
        // 若删除元素不够k个，补删
        for(; k>0; k--) stk.pop_back();
        // 删除头部的0--不能再原元素上删除，要copy
        string result = "";
        bool iszero = true;
        for(char c: stk)
        {
            if(iszero && c=='0') continue;
            iszero = false;
            result += c;
        }
        // 防止result为空字符串
        return result=="" ? "0" : result;
    }
};