/*
给一个二维 board （4 * 4） 和 一个 list of words.
对于board, 每一个元素是一个字母。可以通过这些字母连线组成单词，
连线可以为左，右，上，下，左上，右上，左下，右下，移动一位，共八种移动方式，
但board 里已用过的元素不能再次使用。单词长度不定。问list 中的每一个单词是否能够通过 
board 里的字母连线组成。
*/
#include <vector>
#include <stack>
#include <utility>
#include <iostream>
using namespace std;

bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited, stack<pair<int, int>> &stk,
            string &word, int i, int j, int idx) {
    if (idx == word.size()) return true;
    vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    int m = board.size(), n = board[0].size();
    for (const auto &dir : dirs) {
        int x = i + dir.first, y = j + dir.second;
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[idx] && !visited[x][y]) {
            visited[x][y] = true;
            stk.push({x, y});
            if (helper(board, visited, stk, word, x, y, idx + 1)) return true;
            stk.pop();
            visited[x][y] = false;
        }
    }
    return false;
}

bool isWordInBoard(vector<vector<char>> &board, vector<vector<bool>> &visited, vector<string> &words, int idx) {
    if (idx == words.size()) return true;
    string &word = words[idx];
    int m = board.size(), n = board[0].size();
    stack<pair<int, int>> stk;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0] && !visited[i][j]) {
                visited[i][j] = true;
                stk.push({i, j});
                if (helper(board, visited, stk, word, i, j, 1)) {
                    std::cout << idx + 1 << "," << isWordInBoard(board, visited, words, idx + 1) << std::endl;
                    if (isWordInBoard(board, visited, words, idx + 1)) return true;
                    else {
                        while (!stk.empty()) {
                            int x = stk.top().first, y = stk.top().second;
                            visited[x][y] = false;
                        }
                    }
                }
                if (!stk.empty())
                    stk.pop();
                visited[i][j] = false;
            }
        }
    }
    return false;
}

bool isInBoard(vector<vector<char>> &board, vector<string> &words) {
    if (words.empty()) return true;
    if (board.empty()) return false;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    if (isWordInBoard(board, visited, words, 0)) return true;
    else return false;
}


int main() {
    vector<vector<char>> board {{'u', 'b', 'e', 'r'}, {'r', 'i', 'd', 'e'}, {'e', 'a', 't', 's'}, {'p', 'o', 'o', 'l'}};
    vector<string> words {"uber", "ride", "eats", "pool"};
    std::cout << isInBoard(board, words) << std::endl;

}
