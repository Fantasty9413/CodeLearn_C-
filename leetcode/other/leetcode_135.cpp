// leetcode -- 135

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int len = ratings.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        vector<int> candys(len, 0);

        for(int i=1; i<len; i++)
        {
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
        }

        for(int j=len-2; j>=0; j--)
        {
            if(ratings[j] > ratings[j+1]) right[j] = right[j+1] + 1;
        }

        for(int i=0; i<len; i++) candys[i] = max(left[i], right[i]);

        int candysum = 0;
        for(int x: candys) candysum += x;
        
        return candysum;
    }
};