/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
 */

class Solution {
public:
    int totalNQueens(int n) {

    }
};

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        totalNQueensDFS(pos, 0, res);
        return res;
    }
    void totalNQueensDFS(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) ++res;
        else {
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row, col)) {
                    pos[row] = col;
                    totalNQueensDFS(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int res;
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

    void DFS(vector<string>& board, int row, int& res) {
        int n = board.size();
        if (row == n) {
            ++res;
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
