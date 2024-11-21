class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (vector<int> &wall : walls) grid[wall[0]][wall[1]] = 2;
        for (vector<int> &guard : guards) grid[guard[0]][guard[1]] = 2;
        for (vector<int> &guard : guards) {
            for (int i = guard[0] - 1; i >= 0 && grid[i][guard[1]] != 2; i--) {
                grid[i][guard[1]] = 1;
            }
            for (int i = guard[0] + 1; i < m && grid[i][guard[1]] != 2; i++) {
                grid[i][guard[1]] = 1;
            }
            for (int j = guard[1] - 1; j >= 0 && grid[guard[0]][j] != 2; j--) {
                grid[guard[0]][j] = 1;
            }
            for (int j = guard[1] + 1; j < n && grid[guard[0]][j] != 2; j++) {
                grid[guard[0]][j] = 1;
            }
        }

        int cnt = 0;
        for (int i = 0; i < m;  i++) {
            for (int j = 0; j < n; j++) {
                cnt += (grid[i][j] == 0);
            }
        }

        return cnt;
    }
};