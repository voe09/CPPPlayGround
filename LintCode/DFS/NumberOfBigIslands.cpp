/*
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as 
the island. If two 1 is adjacent, we consider them in the same island. We only
consider up/down/left/right adjacent.

Find the number of islands that size bigger or equal than K.

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
Given the K = 2

return 2
 */

class Solution {
public:
    /*
     * @param : a 2d boolean array
     * @param : an integer
     * @return: the number of Islands
     */
    int numsofIsland(vector<vector<bool>> grid, int k) {
        // Write your code here
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !visited[i][j]) {
                    int cnt = 1;
                    visited[i][j] = true;
                    helper(grid, visited, i, j, cnt);
                    if (cnt >= k) ++res;
                }
            }
        }
        return res;
    }

private:
    void helper(vector<vector<bool>>& grid, vector<vector<bool>>& visited,
            int i, int j, int& cnt) {
        vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();

        for (const auto& dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n
                    && grid[x][y] == 1 && !visited[x][y]) {
                ++cnt;
                visited[x][y] = true;
                helper(grid, visited, x, y, cnt);
            }
        }
    }
};
