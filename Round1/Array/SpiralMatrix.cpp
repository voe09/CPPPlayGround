/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int n = matrix[0].size();
        int m = matrix.size();
        int upper_most = 0;
        int right_most = n - 1;
        int bottom_most = m - 1;
        int left_most = 0;
        while (upper_most <= bottom_most && left_most <= right_most) {
            // upper_most direction
            for (int i = left_most; i <= right_most; ++i) {
                res.push_back(matrix[upper_most][i]);
            }
            upper_most += 1;
            
            // right_most direction
            for (int i = upper_most; i <= bottom_most; ++i) {
                res.push_back(matrix[i][right_most]);
            }
            right_most -= 1;
            
            // bottom_most direction
            if (upper_most <= bottom_most) {
                for (int i = right_most; i >= left_most; --i) {
                    res.push_back(matrix[bottom_most][i]);
                }
                bottom_most -= 1;
            }

            
            // left_most direction
            if (left_most <= right_most) {
                for (int i = bottom_most; i >= upper_most; --i) {
                    res.push_back(matrix[i][left_most]);
                }
                left_most += 1;
            }
       }
       return res;
    }
};
