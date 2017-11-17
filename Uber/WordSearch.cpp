// Word Search

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited,
           int i, int j, int k, string &word) {
    if (k == word.size()) return true;
    
    vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for (const auto &dir : dirs) {
        int x = i + dir.first, y = j + dir.second;
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
            if (board[x][y] == word[k] && !visited[x][y]) {
                visited[x][y] = true;
                if (helper(board, visited, x, y, k + 1, word)) return true;
                visited[x][y] = false;
            }
        }
    }
    return false;
}

bool IsInBoard(vector<vector<char>> &board, string word) {
    if (board.empty()) return false;
    if (word.empty()) return false;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0] && !visited[i][j]) {
                visited[i][j] = true;
                if (helper(board, visited, i, j, 1, word)) return true;
                visited[i][j] = false;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board {{'u', 'b', 'e', 'r'},
                                {'e', 'd', 'i', 'r'},
                                {'e', 'a', 't', 's'},
                                {'a', 'b', 'c', 'd'}};
    std::cout << IsInBoard(board, "uberride") << std::endl;
    std::cout << IsInBoard(board, "haoyang") << std::endl;
}
