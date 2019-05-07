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
#include <vector>
#include <iostream>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    int upMost = 0, lowMost = m - 1;
    int leftMost = 0, rightMost = n - 1;
    vector<int> res;
    while (upMost <= lowMost && leftMost <= rightMost) {
        for (int i = leftMost; i <= rightMost; ++i) {
            res.push_back(matrix[upMost][i]);
        }
        ++upMost;

        for (int i = upMost; i <= lowMost; ++i) {
            res.push_back(matrix[i][rightMost]);
        }
        --rightMost;

        if (leftMost <= rightMost) {
            for (int i = rightMost; i >= leftMost; --i) {
                res.push_back(matrix[lowMost][i]);
            }
            --lowMost;
        }

        if (upMost <= lowMost) {
            for (int i = lowMost; i >= upMost; --i) {
                res.push_back(matrix[i][leftMost]);
            }
            ++leftMost;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = SpiralMatrix(matrix);
    for (const auto &num : res) cout << num << " ";
    cout << endl;
}
