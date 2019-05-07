/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Have you met this question in a real interview? Yes
Example
There exist two distinct solutions to the 4-queens puzzle:

[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]
Challenge 
Can you do it without recursion?
 */

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        vector<vector<string>> res;
        vector<string> board (n, string(n, '.'));
        helper(0, board, res);
        return res;
    }

private:
    void helper(int row, vector<string> &board, vector<vector<string>> &res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int j = 0; j < board.size(); ++j) {
            if (isValid(board, row, j)) {
                board[row][j] = 'Q';
                helper(row + 1, board, res);
                board[row][j] = '.';
            }
        }
    }

    bool isValid(vector<string> &board, int i, int j) {
        vector<pair<int, int>> dirs {{1, 0}, {-1, 0}, {1, 1},
                                    {-1, -1}, {1, -1}, {-1, 1}};
        int n = board.size();
        for (const auto &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (board[x][y] == 'Q') return false;
                x += dir.first, y += dir.second;
            }
        }
        return true;
    }
};
