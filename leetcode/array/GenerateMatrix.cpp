// leetcode-59
# include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n, 0));
        // 每一圈转圈开始的位置
        int startx = 0;
        int starty = 0;
        int count = n/2;        // 循环的圈数（单数就少中间）
        int len = n - 1;        // 填充边长
        int element = 1;        // 填充元素，每次+1
        while(count > 0)
        {
            int i = startx;
            int j = starty;

            for(i=startx,j=starty; i<startx+len; i++)   // 填充上边
            {
                matrix[j][i] = element;
                element++;
            }

            for(i=startx+len,j=starty; j<starty+len; j++)   // 填充右边
            {
                matrix[j][i]= element;
                element++;
            }

            for(i=startx+len,j=starty+len; i>startx; i--)   // 填充上边
            {
                matrix[j][i] = element;
                element++;
            }

            for(i=startx,j=starty+len; j>starty; j--)   // 填充上边
            {
                matrix[j][i] = element;
                element++;
            }            

            startx++;
            starty++;
            count--;
            len = len - 2;
        }
        if(element == n*n)
        {matrix[n/2][n/2] = n*n;}
        
        return matrix;
    }
};