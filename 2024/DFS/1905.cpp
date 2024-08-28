class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] && !visited[i][j]) {
                    visited[i][j] = true;
                    bool hasWater = false;
                    helper(grid1, grid2, i, j, visited, hasWater);
                    cnt += hasWater ? 0 : 1;
                }
            }
        }

        return cnt;
    }

    void helper(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<bool>>& visited, bool& hasWater) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid1.size(), n = grid1[0].size();
        
        if (grid1[i][j] == 0) hasWater = true;

        for (pair<int, int>& dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x < 0 || x >= m || y < 0 || y >= n || grid2[x][y]==0 || visited[x][y]) continue;
            visited[x][y] = true;
            helper(grid1, grid2, x, y, visited, hasWater);
        }
    }
};