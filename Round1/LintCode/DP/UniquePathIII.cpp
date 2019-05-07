/*
Follow up for "Unique Paths II": http://lintcode.com/en/problem/unique-paths-ii/

Now each grid contains a value, so each path also has a value. 
Find the sum of all the unique values paths.

Have you met this question in a real interview? Yes
Example
For example,

[
  [1,1,2],
  [1,2,3],
  [3,2,4]
]
There are 2 unique value path:
[1,1,2,3,4] = 11
[1,1,2,2,4] = 10

return 21
 */

class Solution {
public:
    /*
     * @param : an array of arrays
     * @return: the sum of all unique weighted paths
     */
    int uniqueWeightedPaths(vector<vector<int>>& grid) {
        // write your codes here
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<unordered_set<int>>> dp (m, vector<unordered_set<int>> (n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j].insert(grid[i][j]);
                if (j != 0) {
                    for (const auto &num : dp[i][j - 1]) {
                        dp[i][j].insert(num + grid[i][j]);
                    }
                }

                if (i != 0) {
                    for (const auto &num : dp[i - 1][j]) {
                        dp[i][j].insert(num + grid[i][j]);
                    }
                }
            }
        }
        int res = 0;
        for (const auto &num : dp[m - 1][n - 1])
            res += num;
        return res;
    }
};
