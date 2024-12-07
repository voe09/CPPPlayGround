// TLE
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            visited[t[1]][t[2]] = true;
            if (t[1] == m - 1 && t[2] == n - 1) return t[0];
            for (pair<int, int> &dir : dirs) {
                int x = t[1] + dir.first, y = t[2] + dir.second;
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                int time = max(grid[x][y], t[0]);
                pq.push({time, x, y});
            }
        }

        return -1;
    }
};