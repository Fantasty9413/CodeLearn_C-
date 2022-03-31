# include <iostream>
# include <string>
using namespace std;

void KMP_GetNext(int* next, const string &s)
{
    // 初始化
    int j = 0;
    next[0] = 0;

    for(int i=1; i<s.size(); i++)
    {
        // 前缀不相同的处理
        while(j>0 && s[i]!=s[j])
        {
            j = next[j-1];
        }
        // 前缀相同的处理
        if(s[i] == s[j])
        {
            j++;
        }
        // 更新next数组
        next[i] = j;
    }
}

int main()
{
    string s = "aabaabaa";
    int next[8];
    KMP_GetNext(next, s);

    int i = 0;
    while(i < s.size())
    {
        std::cout << next[i] << " ";
        i++;
    }

    return 0;
}