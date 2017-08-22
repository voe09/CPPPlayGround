/*
Given an m x n matrix of non-negative integers representing the height of 
each unit cell in a continent, the "Pacific ocean" touches the left and 
top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell 
to another one with height equal or lower.

Find the list of grid coordinates where water can flow to 
both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
 */

// 这题从边开始dfs会更好，我这做法略慢

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> flows(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                DFS(i, j, matrix, flows);
                if (flows[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    void DFS(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& flows) {
        bool is_pacific = false, is_atlantic = false;
        stack<pair<int, int>> stk;
        stk.push({i, j});
        int m = flows.size(), n = flows[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        while (!stk.empty()) {
            pair<int, int> cur = stk.top();
            stk.pop();
            int x = cur.first, y = cur.second;
            if (flows[x][y] == 1) {
                flows[i][j] = 1;
                return;
            } 
            visited[x][y] = 1;
            if (x == 0 || y == 0) is_pacific = true;
            if (x == m - 1 || y == n - 1)
                is_atlantic = true;
            if (is_pacific && is_atlantic) {
                flows[i][j] = 1;
                return;
            }
            // up
            if (x > 0 && matrix[x][y] >= matrix[x - 1][y]
                    && !visited[x - 1][y]) {
                stk.push({x - 1, y});
            }
            // down
            if (x < m - 1 && matrix[x][y] >= matrix[x + 1][y] 
             f       && !visited[x + 1][y]) {
                stk.push({x + 1, y});
            }
            // left
            if (y > 0 && matrix[x][y] >= matrix[x][y - 1]
                    && !visited[x][y - 1]) {
                stk.push({x, y - 1});
            }
            // right
            if (y < n - 1 && matrix[x][y] >= matrix[x][y + 1]
                    && !visited[x][y + 1]) {
                stk.push({x, y + 1});
            }
        }
        flows[i][j] = -1;
    }
};
