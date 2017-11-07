/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Have you met this question in a real interview? Yes
Example
Given board =

[
  "ABCE",
  "SFCS",
  "ADEE"
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */

class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        // write your code here
        if (board.empty()) return false;
        if (word.empty()) return true;

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = true;
                if (helper(board, visited, word, i, j, 0)) return true;
                visited[i][j] = false;
            }
        }
        
        return false;
    }

private:
    bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited,
            string &word, int i, int j, int k) {
        if (k == word.size() - 1 && board[i][j] == word[k]) return true;
        if (board[i][j] != word[k]) return false;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                visited[x][y] = true;
                if (helper(board, visited, word, x, y, k + 1)) return true;
                visited[x][y] = false;
            }
        }
        return false;
    }
};
