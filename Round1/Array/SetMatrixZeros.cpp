/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int m = matrix.size();
        int n = matrix[0].size();
        int row_store_col_idx = -1;
        int col_store_row_idx = -1;
        
        // search the first 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row_store_col_idx = i;
                    col_store_row_idx = j;
                    goto endloop;
                }
            }
        }
        
        endloop:
        std::cout << row_store_col_idx << "," << col_store_row_idx;
        if (row_store_col_idx != -1 && col_store_row_idx != -1) {
            // sotre the row and col idx that contains 0 in this row
            for (int i = 0; i < m; ++i) {
                if (i != row_store_col_idx) {
                    for (int j = 0; j < n; ++j) {
                        if (j != col_store_row_idx) {
                            if (matrix[i][j] == 0) {
                                matrix[row_store_col_idx][j] = 0;
                                matrix[i][col_store_row_idx] = 0;
                            }
                        }
                    }
                }
            }
        
            // fill 0 based on the info in row_store_col_idx
            for (int j = 0; j < n; ++j) {
                if (j != col_store_row_idx) {
                    if (matrix[row_store_col_idx][j] == 0) {
                        for (int i = 0; i < m; ++i) {
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
        
            // fill 0 based on the info in col_store_row_idx
            for (int i = 0; i < m; ++i) {
                if (i != row_store_col_idx) {
                    if (matrix[i][col_store_row_idx] == 0) {
                        for (int j = 0; j < n; ++j) {
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
        
            // fill 0 on row_store_col_idx
            for (int j = 0; j < n; ++j) {
                matrix[row_store_col_idx][j] = 0;
            }
        
            // fill 0 on col_store_row_idx
            for (int i = 0; i < m; ++i) {
                matrix[i][col_store_row_idx] = 0;
            }
        }
        return;
    }
};
