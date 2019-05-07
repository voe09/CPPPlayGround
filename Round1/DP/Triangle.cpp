/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may 
move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = i; j >= i; --j) {
                if (j == 0)
                    dp[j] = dp[j] + triangle[i][j];
                else
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
        }
        int minTotal = INT_MAX;
        for (int i = 0; i < n; ++i)
            minTotal = min(minTotal, dp[i]);
        return minTotal;
    }
};



class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()) {
            return 0;
        }
        int row = triangle.size();
        vector<int> dp;
        dp.resize(row);
        //用最底层的数据初始化
        for(int i = 0; i < dp.size(); i++) {
            dp[i] = triangle[row-1][i];
        }

        for(int i = row - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
