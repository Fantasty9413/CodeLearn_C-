// leetcode -- 1790

# include <vector>
# include <map>
# include <string>
using namespace std;

class Solution 
{
    public:
    bool areAlmostEqual(string s1, string s2) 
    {
        // 先用字符串长度判断
        if(s1.size()!=s2.size()) return false;
        
        // 字符串比较
        map<int, int> strdiff;          // 记录字符不同的下标和字符差
        for(int i=0; i<s1.size(); i++)
        {
            int diff = s1[i] - s2[i];  // 字符ascii码偏差
            if(diff!=0) strdiff.emplace(i, diff);
        }

        // 结果分析
        if(strdiff.size()==0) return true;
        if(strdiff.size()==1) return false;
        if(strdiff.size()==2)
        {
            int index1 = strdiff.begin()->first;
            int index2 = (++strdiff.begin())->first;
            if(s1[index1]==s2[index2] && s1[index2]==s2[index1]) return true;
            else return false;
        }
        if(strdiff.size()>2) return false;
        return false;
    }
};

int main()
{
    string str1 = "bank";
    string str2 = "kanb";
    Solution s;
    s.areAlmostEqual(str1, str2);

    return 0;
}