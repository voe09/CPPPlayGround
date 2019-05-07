/*
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.

Have you met this question in a real interview? Yes
Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.
 */

class Solution {
public:
    /*
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    void helper(vector<vector<bool>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        grid[i][j] = false;
        for (const auto &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y]) helper(grid, x, y);
            }
        }
    }

    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++cnt;
                    helper(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
