/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */


// TLE
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int max_path = 0;
        map<pair<int, int>, int> ht;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr = longestIncreasingPath(matrix, i, j, ht);
                max_path = max(max_path, curr);
            }
        }
        return max_path;
    }

private:
    int longestIncreasingPath(vector<vector<int>>& matrix, int i, int j,
            map<pair<int, int>, int>& ht) {
        int m = matrix.size(), n = matrix[0].size();
        int path = 0;
        stack<tuple<int, int, int>> stk;
        stk.push({i, j, 1});
        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            int x = std::get<0>(cur), y = std::get<1>(cur), len = std::get<2>(cur);
            path = max(path, len);
            // up
            if (x > 0 && matrix[x - 1][y] > matrix[x][y]) {
                pair<int, int> coord{x - 1, y};
                if (ht.count(coord)) path = max(path, len + ht[coord]);
                else {
                    stk.push({x - 1, y, len + 1});
                }
            }
            // down
            if (x < m - 1 && matrix[x + 1][y] > matrix[x][y]) {
                pair<int, int> coord{x + 1, y};
                if (ht.count(coord)) path = max(path, len + ht[coord]);
                else {
                    stk.push({x + 1, y, len + 1});
                }
            }
            // left
            if (y > 0 && matrix[x][y - 1] > matrix[x][y]) {
                pair<int, int> coord{x, y - 1};
                if (ht.count(coord)) path = max(path, len + ht[coord]);
                else {
                    stk.push({x, y - 1, len + 1});
                }
            }
            // right
            if (y < n - 1 && matrix[x][y + 1] > matrix[x][y]) {
                pair<int, int> coord{x, y + 1};
                if (ht.count(coord)) path = max(path, len + ht[coord]);
                else {
                    stk.push({x, y + 1, len + 1});
                }
            }
        }
        pair<int, int> tmp{i, j};
        ht[tmp] = path;
        return path;
    }
};



// DFS + Memorization solution.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int res = 0;
        vector<vector<int>> max_lengths(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, longestpath(matrix, i, j, &max_lengths));
            }
        }

        return res;
    }

private:
    int longestpath(const vector<vector<int>>& matrix, const int i, const int j,
                    vector<vector<int>> *max_lengths) {
        if ((*max_lengths)[i][j] > 0) {
            return (*max_lengths)[i][j];
        }

        int max_depth = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto& d : directions) {
            const int x = i + d.first, y = j + d.second;
            if (x >= 0 && x < matrix.size() &&
                y >= 0 && y < matrix[0].size() &&
                matrix[x][y] < matrix[i][j]) {
                max_depth = max(max_depth,
                                longestpath(matrix, x, y, max_lengths));
            }
        }

        (*max_lengths)[i][j] = max_depth + 1;
        return (*max_lengths)[i][j];
    }
};
