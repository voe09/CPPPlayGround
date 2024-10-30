class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{1, -1}, {0, -1}, {-1, -1}};

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < m; i++) dp[i][0] = 0;
        // loop ordering matters
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                for (const pair<int, int> &dir : dirs) {
                    int x = i + dir.first, y = j + dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || dp[x][y] < 0 || grid[x][y] >= grid[i][j]) continue;
                    dp[i][j] = max(dp[x][y] + 1, dp[i][j]);
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};