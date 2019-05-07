/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            if (i > 1) {
                vector<int> lastRow = res[i - 1];
                for (int j = 1; j < i; ++j) {
                    row[j] = lastRow[j - 1] + lastRow[j];
                }
            }
            res.push_back(row);
        }
        return res;
    }
};


/*
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for(int i = 1; i < rowIndex + 1; ++i) {
            res[i] = 1;
            for (int j = i - 1; j > 0; --j)
                res[j] = res[j] + res[j - 1];
        }
        return res;
    }
};

