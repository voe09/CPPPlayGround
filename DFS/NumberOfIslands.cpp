/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        set<pair<int, int>> visited;
        int m = grid.size(), n = grid[0].size();
        int number = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pair<int, int> coord{i, j};
                if (grid[i][j] == '0' || visited.count(coord)) continue;
                ++number;
                stack<pair<int, int>> stk;
                stk.push(coord);
                while (!stk.empty()) {
                    pair<int, int> tmp = stk.top();
                    stk.pop();
                    visited.insert(tmp);
                    int x = tmp.first, y = tmp.second;
                    if (x > 0 && grid[x - 1][y] == '1' && visited.count({x - 1, y}) == 0) {
                        stk.push({x - 1, y});
                    }
                    
                    if (x < m - 1 && grid[x + 1][y] == '1' && visited.count({x + 1, y}) == 0) {
                        stk.push({x + 1, y});
                    }
                    
                    if (y > 0 && grid[x][y - 1] == '1' && visited.count({x, y - 1}) == 0) {
                        stk.push({x, y - 1});
                    }
                    
                    if (y < n - 1 && grid[x][y + 1] == '1' && visited.count({x, y + 1}) == 0) {
                        stk.push({x, y + 1});
                    }
                }
            }
        }
        return number;
    }
};
