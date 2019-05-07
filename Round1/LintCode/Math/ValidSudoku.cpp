/*
Determine whether a Sudoku is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character ..

 Notice

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Have you met this question in a real interview? Yes
Clarification
What is Sudoku?

http://sudoku.com.au/TheRules.aspx
https://zh.wikipedia.org/wiki/%E6%95%B8%E7%8D%A8
https://en.wikipedia.org/wiki/Sudoku
http://baike.baidu.com/subview/961/10842669.htm
Example
The following partially filed sudoku is valid.

Valid Sudoku
 */

class Solution {
public:
    /*
     * @param board: the board
     * @return: whether the Sudoku is valid
     */
    bool isValidSudoku(vector<vector<char>> &board) {
        // write your code here
        // test cols and rows
        for (int i = 0; i < board.size(); ++i) {
            vector<bool> row_visited (board.size(), false);
            vector<bool> col_visited (board.size(), false);
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int idx = board[i][j] - '1';
                    if (!row_visited[idx]) row_visited[idx] = true;
                    else return false;
                }

                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    int idx = board[j][i] - '1';
                    if (!col_visited[idx]) col_visited[idx] = true;
                    else return false;
                }
            }
        }
        // test blocks
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                vector<bool> visited (board.size(), false);
                for (int k = 0; k < board.size(); ++k) {
                    if (board[i + k / 3][j + k % 3] >= '1' && board[i + k / 3][j + k % 3] <= '1') {
                        int idx = board[i + k / 3][j + k % 3] - '1';
                        if (!visited[idx]) visited[idx] = true;
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};
