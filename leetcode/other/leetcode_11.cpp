# include <iostream>
# include <vector>
using namespace std;

class Solution 
{
    public:
    int maxArea(vector<int>& height) 
    {
        int MaxWater =0;
        int len = height.size();
        int leftindex = 0;
        int rightindex = len -1;

        for(; leftindex < len; leftindex++)       // 左指针移动--头部
        {
            // 右指针移动--尾部
            for(; rightindex > leftindex; rightindex--)
            {
                int width = rightindex - leftindex;
                int temp = 0;       // 右壁无法高于左壁情况下的最大数量记录
                if(height[rightindex] >= height[leftindex])  // 右壁高于左壁--以左壁高度为准--直接退出
                {
                    int hei = height[leftindex]; // 左壁为高度
                    int water = hei * width;
                    if(water > MaxWater) MaxWater = water;
                    break;
                }
                else // 右壁无法高于左壁
                {
                    int hei = height[rightindex];
                    int water = hei * width;
                    if(water > temp) temp = water;
                }
                if(temp > MaxWater) MaxWater = temp;
            }
        }
        return MaxWater;
    }
};

int main()
{
    vector<int> num = {1,9,6,2,5,4,8,3,7};
    Solution s;
    int result = s.maxArea(num);
    cout << "result: " << result;

    return 0;
}