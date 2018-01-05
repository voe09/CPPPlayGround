/*
Given a 2D boolean matrix filled with False and True, find the largest rectangle
containing all True and return its area.

Have you met this question in a real interview? Yes
Example
Given a matrix:

[
  [1, 1, 0, 0, 1],
  [0, 1, 0, 0, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 0, 0, 1]
]
return 6.
 */

/*
http://www.cnblogs.com/grandyang/p/4322667.html
 */

class Solution {
public:
    /*
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<vector<int>>> dp (m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <=n; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j][0] += dp[i - 1][j][0] + 1;
                    dp[i][j][1] += dp[i][j - 1][1] + 1;
                }
            }
        }
    }
};

