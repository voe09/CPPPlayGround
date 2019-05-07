/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string cur = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isValid(board, cur, word, i, j)) {
                    cur = cur + board[i][j];
                    visited[i][j] = true;
                    if (DFS(board, visited, cur, i, j, word)) return true;
                    visited[i][j] = false;
                    cur.pop_back();
                }
            }
        }
        return false;
    }

private:
    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visited,
            string& cur, int i, int j, string& word) {
        if (cur == word) {
            return true;
        }
        vector<pair<int, int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        int m = board.size(), n = board[0].size();
        for (const auto& pair : directions) {
            int x = i + pair.first, y = j + pair.second;
            if (x >= 0 && x < m && y >= 0 && y < n
                && isValid(board, cur, word, x, y) && !visited[x][y]) {
                cur = cur + board[x][y];
                visited[x][y] = true;
                if (DFS(board, visited, cur, x, y, word)) return true;
                visited[x][y] = false;
                cur.pop_back();
            }
        }
        
        return false;
    }

    bool isValid(vector<vector<char>>& board, string& cur, string& word, int i, int j) {
        int len = cur.size();
        if (word[len] != board[i][j]) return false;
        else return true;
    }
};
