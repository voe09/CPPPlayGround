/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 
for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
 */

// 首先遍历一次矩阵，将值为0的点都存入queue，将值为1的点改为INT_MAX
// 然后开始BFS遍历，从queue中取出一个数字，遍历其周围四个点，如果越界或者周围点
// 的值小于等于当前值，则直接跳过。因为周围点的距离更小的话，就没有更新的必要，
// 否则将周围点的值更新为当前值加1，然后把周围点的坐标加入queue

// http://www.cnblogs.com/grandyang/p/6602288.html

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) q.push({i, j});
                else matrix[i][j] = INT_MAX;
            }
        }
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n ||
                matrix[x][y] <= matrix[t.first][t.second]) continue;
                matrix[x][y] = matrix[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        return matrix;
    }
};
