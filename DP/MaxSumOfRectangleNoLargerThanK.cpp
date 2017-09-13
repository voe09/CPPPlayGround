/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a 
rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is 
the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
 */

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1]
                             - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int res = INT_MIN;
        for (int r = m; r >= 0; --r) {
            for (int c = n; c >= 0; --c) {
                for (int l = r - 1; l >= 0; --l) {
                    for (int d = c - 1; d >= 0; --d) {
                        int tmp = sums[r][c] - sums[r][d] - sums[l][c] + sums[l][d];
                        if (tmp <= k)
                            res = max(res, tmp);
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        int sum[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = matrix[i][j];
                if (i > 0) t += sum[i - 1][j];
                if (j > 0) t += sum[i][j - 1];
                if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
                sum[i][j] = t;
                for (int r = 0; r <= i; ++r) {
                    for (int c = 0; c <= j; ++c) {
                        int d = sum[i][j];
                        if (r > 0) d -= sum[r - 1][j];
                        if (c > 0) d -= sum[i][c - 1];
                        if (r > 0 && c > 0) d += sum[r - 1][c - 1];
                        if (d <= k) res = max(res, d);
                    }
                }
            }
        }
        return res;
    }
};
