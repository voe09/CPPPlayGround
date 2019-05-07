/*
Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

Have you met this question in a real interview? Yes
Example
Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
 */

class Solution {
public:
    /*
     * @param n: An integer
     * @return: a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // write your code here
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int curr = 1;
        int left = 0, right = n - 1, btm = 0, top = n - 1;
        while (curr <= n * n) {
            for (int i = left; i <= right; ++i) {
                matrix[btm][i] = curr;
                ++curr;
            }
            ++btm;
            
            for (int i = btm; i <= top; ++i) {
                matrix[i][right] = curr;
                ++curr;
            }
            --right;
            if (btm <= top) {
                for (int i = right; i >= left; --i) {
                    matrix[top][i] = curr;
                    ++curr;
                }
                --top;
            }

            if (left <= right) {
                for (int i = top; i >= btm; --i) {
                    matrix[i][left] = curr;
                    ++curr;
                }
                ++left;
            }
        }
        return matrix;
    }
};
