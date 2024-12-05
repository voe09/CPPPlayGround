class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    grid[i][j] = '2';
                    helper(grid, i, j);
                }
            }
        }
        return cnt;
    }

private:
    void helper(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (pair<int, int> &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] != '1') continue;
            grid[x][y] = '2';
            helper(grid, x, y);
        }
    }
};