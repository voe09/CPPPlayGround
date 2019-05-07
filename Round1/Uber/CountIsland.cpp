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
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

void helper(vector<vector<int>> &matrix, int i, int j, vector<vector<bool>> &visited) {
    vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = matrix.size(), n = matrix[0].size();

    for (const auto &dir : dirs) {
        int x = i + dir.first, y = j + dir.second;
        if (x >= 0 && x < m && y >= 0 && y < n) {
            if (matrix[x][y] == 1 && !visited[x][y]) {
                visited[x][y] = true;
                helper(matrix, x, y, visited);
            }
        }
    }
}

int numOfIslands(vector<vector<int>> matrix) {
    int cnt = 0;
    if (matrix.empty()) return cnt;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                ++cnt;
                visited[i][j] = true;
                helper(matrix, i, j, visited);
            }
        }
    }
    return cnt;
}

int main() {
    vector<vector<int>> matrix {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0},
                                {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    cout << numOfIslands(matrix) << endl;
}
