// N-queen puzzle
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

bool isValid(vector<string> &puzzle, int row, int col) {
    vector<pair<int, int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
                                 {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    for (const auto &dir : dirs) {
        int x = row + dir.first, y = col + dir.second;
        while (x >= 0 && x < puzzle.size()
                    && y >= 0 && y < puzzle.size()) {
                if (puzzle[x][y] == 'Q') return false;
                x += dir.first, y += dir.second;
        }
    }
    return true;
}

void helper(int row, vector<string> &curr, vector<vector<string>> &res) {
    if (row == curr.size()) {
        res.push_back(curr);
        return;
    }
    
    for (int i = 0; i < curr.size(); ++i) {
        if (isValid(curr, row, i)) {
            curr[row][i] = 'Q';
            helper(row + 1, curr, res);
            curr[row][i] = '.';
        }
    }
}

vector<vector<string>> nQueen(int n) {
    if (n == 0) return {};
    vector<vector<string>> res;
    vector<string> curr (n, string(n, '.'));
    helper(0, curr, res);
    return res;
}

int main() {
    vector<vector<string>> res = nQueen(4);
    for (const auto &puzzle : res) {
        std::cout << "############" << std::endl;
        for (const auto &s : puzzle) {
            std::cout << s << std::endl;
        }
    }
}
