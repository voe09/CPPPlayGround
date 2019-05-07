/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' 
 * placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 */

/* For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */

/*
 * idea: DFS, every time search for depthest queen first
 */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<int> stack;
        std::vector<std::vector<string>> res;
        if (n == 1) {
            std::vector<string> config{"Q"};
            res.push_back(config);
            return res;
        }
        stack.push_back(0);
        DFS(stack, res, n, 0);
        return res;
    }

private:
    void DFS(std::vector<int> &stack,
             std::vector<std::vector<string>> &res, int n, int start_point) {
        if (stack.size() == 0 && start_point > n - 1) return;
        int next_row = stack.size();
        bool find_valid = false;
        for (int i = start_point; i < n; ++i) {
            bool is_valid = true;
            for (int j = 0; j < stack.size(); ++j) {
                if (stack[j]  == i) {
                    is_valid = false;
                    break;
                }
                if (std::abs(j - next_row) == std::abs(stack[j] - i)) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                find_valid = true;
                if (next_row == n - 1) {
                    stack.push_back(i);
                    std::vector<string> config;
                    for (int k = 0; k < n; ++k) {
                        std::string row (n, '.');
                        row[stack[k]] = 'Q';
                        config.push_back(row);
                    }
                    res.push_back(config);
                    stack.pop_back();
                    DFS(stack, res, n, i + 1);
                    return;
                    return;
                } else {
                    stack.push_back(i);
                    DFS(stack, res, n, 0);
                    return;
                }
            }
        }

        if (!find_valid) {
            int start = stack.back() + 1;
            stack.pop_back();
            DFS(stack, res, n, start);
            return;
        }
    }
};




class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        DFS(board, 0, res);
        return res;
    }

private:
    bool isValid(vector<string>& board, int i, int j) {
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int n = board.size();
        for (const auto& pair : directions) {
            int x = i + pair.first, y = j + pair.second;
            while (x >= 0 && x < n
                    && y >= 0 && y < n) {
                if (board[x][y] == 'Q') return false;
                x += pair.first, y += pair.second;
            }
        }
        return true;
    }

    void DFS(vector<string>& board, int row, vector<vector<string>>& res) {
        int n = board.size();
        if (row == n) {
            res.push_back(board);
            return;
        };

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                DFS(board, row + 1, res);
                board[row][col] = '.';
            }
        }
    }
};
