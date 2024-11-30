// BFS also works, less intuitive
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n));
        pq.push({0, 0, 0});
        visited[0][0] = true;
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            if (curr[1] == m - 1 && curr[2] == n - 1) return curr[0];

            for (pair<int, int> &dir : dirs) {
                int x = curr[1] + dir.first, y = curr[2] + dir.second;
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                int cost = curr[0] + (grid[x][y] == 1 ? 1 : 0);
                visited[x][y] = true;
                pq.push({cost, x, y});
            }
        }

        return -1;
    }

private:
    vector<pair<int, int>> dirs  = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};