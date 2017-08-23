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
        return DFS(board, visited, cur, word);
    }

private:
    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visited,
            string& cur, string& word) {
        if (cur == word) {
            return false;
        }
        vector<pair<int, int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    }
};
