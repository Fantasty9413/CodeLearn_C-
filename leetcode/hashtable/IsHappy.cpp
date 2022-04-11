// leetcode - 202

# include <iostream>
# include <set>
using namespace std;

class Solution {
public:
    int getsum(int n)       // 获取平方和
    {
        int sum = 0;
        while(n != 0)
        {
            sum = sum + (n%10)*(n%10);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        set<int> nset;
        while(1)
        {
            // n放入set中
            nset.emplace(n);

            // 更新n的值
            n = this->getsum(n);

            // 检查是不是快乐数
            if(n==1)
            {
                return true;
            }            

            // 查找n是否在集合中出现
            if(nset.count(n) == 1)
            {
                return false;
            }
        }
        
        return false;
    }
};

int main()
{
    Solution solution;
    cout << solution.getsum(19) << endl;

    return 0;
}