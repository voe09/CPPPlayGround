/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int num_row = board.size();
        int num_col = board[0].size();

        for (int row = 0; row < num_row; ++row) {
            unordered_map<char, int> lookup;
            for (int col = 0; col < num_col; ++col) {
                if (board[row][col] != '.') {
                    if (lookup.count(board[row][col])) return false;
                    lookup[board[row][col]] = 0;
                }
            }
        }

        for (int col = 0; col < num_col; ++col) {
            unordered_map<char, int> lookup;
            for (int row = 0; row < num_row; ++row) {
                if (board[row][col] != '.') {
                    if (lookup.count(board[row][col])) return false;
                    lookup[board[row][col]] = 0;
                }
            }
        }

        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j += 3) {
                unordered_map<char, int> lookup;
                for (int row = i; row < i + 3; ++row) {
                    for (int col = j; col < j + 3; ++j) {
                        if (board[row][col] != '.') {
                            if (lookup.count(board[row][col])) return false;
                            lookup[board[row][col]] = 0;
                        }
                    }
                }
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        // Check row constraints.
        for (int i = 0; i < 9; ++i) {
            if (anyDuplicate(board, i, i + 1, 0, 9)) {
                return false;
            }
        }

        // Check column constraints.
        for (int j = 0; j < board.size(); ++j) {
            if (anyDuplicate(board, 0, 9, j, j + 1)) {
                return false;
            }
        }

        // Check region constraints.
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (anyDuplicate(board, i, i + 3, j, j + 3)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    // Return true if subarray board[start_row : end_row - 1][start_col : end_col - 1]
    // contains any duplicates in [1 : num_elements]; otherwise return false.
    bool anyDuplicate(const vector<vector<char>>& board, int start_row, int end_row,
                      int start_col, int end_col) {
        bitset<9> is_present;
        for (int i = start_row; i < end_row; ++i) {
            for (int j = start_col; j < end_col; ++j) {
                if (board[i][j] != '.') {
                    if (is_present[board[i][j] - '1']) {
                        return true;
                    }
                    is_present.flip(board[i][j] - '1');
                }
            }
        }
        return false;
    }
};


// Time:  O(9^2)
// Space: O(9)
// More generic solution.
class Solution2 {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        // Check row constraints.
        for (int i = 0; i < board.size(); ++i) {
            if (anyDuplicate(board, i, i + 1, 0, board.size(), board.size())) {
                return false;
            }
        }

        // Check column constraints.
        for (int j = 0; j < board.size(); ++j) {
            if (anyDuplicate(board, 0, board.size(), j, j + 1, board.size())) {
                return false;
            }
        }

        // Check region constraints.
        int region_size = sqrt(board.size());
        for (int i = 0; i < board.size(); i += region_size) {
            for (int j = 0; j < board.size(); j += region_size) {
                if (anyDuplicate(board,
                                 i, i + region_size,
                                 j, j + region_size,
                                 board.size())) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    // Return true if subarray board[start_row : end_row - 1][start_col : end_col - 1]
    // contains any duplicates in [1 : num_elements]; otherwise return false.
    bool anyDuplicate(const vector<vector<char>>& board, int start_row, int end_row,
                      int start_col, int end_col, int num_elements) {
        vector<bool> is_present(num_elements + 1, false);
        for (int i = start_row; i < end_row; ++i) {
            for (int j = start_col; j < end_col; ++j) {
                if (board[i][j] != '.') {
                    if (is_present[board[i][j] - '0']) {
                        return true;
                    }
                    is_present[board[i][j] - '0'] = true;
                }
            }
        }
        return false;
    }
};
