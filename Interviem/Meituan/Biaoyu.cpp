# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution
{
    public: 
    void getAllSubstring(string s, vector<string> &res)
    {
        vector<string>::iterator itr = res.begin();
        for(int i=0; i<s.size(); i++)
        {
            for(int j=1; j<=s.size()-i; j++)
            {
                res.push_back(s.substr(i, j));
                itr++;
            }
        }
    }

    bool isSubsequence(string s, string t) 
    {
        // s:匹配串
        // t:模式串
        // 判断s是不是t的序列
        int i=0,j=0; //两个指针，i为s的指针,j为t的指针
        while(i<s.size()&&j<t.size())
        {
            while(t[j]!=s[i] && j<t.size()) ++j;  //在t中找s里i对应的字母
            if(j<t.size()) {++i;++j;}
            
        }
        if(i>=s.size())
            return true;
        else
            return false;        
    } 

    int getresult(string s, string t)
    {
        int num = 0;
        vector<string> res;
        getAllSubstring(s, res);        // 获取子串
        for(int i=0; i<res.size(); i++)
        {
            // isSubsequence(t, res[i])==1 ? num++ : num = num;
            if (isSubsequence(t, res[i]))
            {
                num++;
            }
        }
        return num;
    }       
};

int main()
{
    string s;
    string t;
    cin >> s;
    cin >> t;
    Solution solution;
    cout << solution.getresult(s, t) << endl;

    return 0;
}