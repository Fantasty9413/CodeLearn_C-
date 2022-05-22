# include <vector>
# include <string>
using namespace std;

class Solution 
{
    string result;
    vector<string> results;
    vector<char> backets = {'(', ')'};
    void backtracking(int left, int right, int n)
    {
        // left: 放入了的左括号的个数
        // right: 放入了的有括号的个数
        // 终止条件
        if(result.size()==2*n)
        {
            if(left==right) results.push_back(result);
            return;
        }
        // 集合中选择元素
        for(int i=0; i<backets.size(); i++)
        {
            // if(left>=n) continue;
            // if(right>=n) continue;
            if(right>left) continue;
            // 节点操作            
            result.push_back(backets[i]);
            // 递归
            if(i==0) backtracking(left+1, right, n);     // 放入一个左括号   
            else if(i==1) backtracking(left, right+1, n);  // 放入一个右括号
            // 回溯操作
            result.pop_back();
        }
    }
    public:
    vector<string> generateParenthesis(int n) 
    {
        result.clear();
        results.clear();
        backtracking(0, 0, n);
        return results;
    }
};

int main()
{
    int n = 1;
    Solution solution;
    vector<string> results = solution.generateParenthesis(1);

    return 0;
}