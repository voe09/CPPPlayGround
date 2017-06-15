/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        
        int row_beg = 0;
        int row_end = n - 1;
        int col_beg = 0;
        int col_end = n - 1;
        int current_idx = 0;
        
        while (row_beg <= row_end && col_beg <= col_end) {
            // upper most direction
            for (int i = col_beg; i <= col_end; ++i) {
                current_idx += 1;
                res[row_beg][i] = current_idx;
            }
            row_beg += 1;
            
            // right most direction
            for (int i = row_beg; i <= row_end; ++i) {
                current_idx += 1;
                res[i][col_end] = current_idx;
            }
            col_end -= 1;
            
            // bottom most direction
            if (row_beg <= row_end) {
                for (int i = col_end; i >= col_beg; --i) {
                    current_idx += 1;
                    res[row_end][i] = current_idx;
                }
            }
            row_end -= 1;
            
            // left most direction
            if (col_beg <= col_end) {
                for (int i = row_end; i >= row_beg; --i) {
                    current_idx += 1;
                    res[i][col_beg] = current_idx;
                }
            }
            col_beg += 1;
        }
        return res;
    }
};
