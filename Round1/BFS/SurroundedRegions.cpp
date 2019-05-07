/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions 
surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */

// BFS。对于每一个O，扫描其相邻节点，然后标示之，如果一个联通区域中有任何一个
// O在边界上，则保留之，否则清除该联通域

// TLE
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        set<pair<int, int>> visited;
        set<pair<int, int>> flip;
        set<pair<int, int>> region;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') continue;
                pair<int, int> coord(i, j);
                if (visited.count(coord)) continue;
                else {
                    visited.insert(coord);
                    region.insert(coord);
                    queue<pair<int, int>> q;
                    q.push(coord);
                    bool is_flip = true;
                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        int x = curr.first, y = curr.second;
                        if (x == 0 || x == m - 1 
                            || y == 0 || y == n - 1)
                            is_flip = false;
                        if (x < m - 1 && board[x + 1][y] == 'O') {
                            visited.insert({x + 1, y});
                            region.insert({x + 1, y});
                            q.push({x + 1, y});
                        }
                        if (y < n - 1 && board[x][y + 1] == 'O') {
                            visited.insert({x, y + 1});
                            region.insert({x, y + 1});
                            q.push({x, y + 1});
                        }
                        if (y > 0 && board[x][y - 1] == 'O') {
                            pair<int, int> tmp(x, y - 1);
                            if (!visited.count(tmp)) {
                                visited.insert(tmp);
                                region.insert(tmp);
                                q.push(tmp);
                            }
                        }
                        if (x > 0 && board[x - 1][y] == 'O') {
                            pair<int, int> tmp(x - 1, y);
                            if (!visited.count(tmp)) {
                                visited.insert(tmp);
                                region.insert(tmp);
                                q.push(tmp);
                            }
                        }
                    }
                    if (!is_flip) region.clear();
                    else {
                        for (const auto& coord: region)
                            flip.insert(coord);
                        region.clear();
                    }
                }
            }
        }
        for (const auto& coord : flip) {
            board[coord.first][coord.second] = 'X';
        }
        return;
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'X' || board[0][i] == 'U') continue;
            BFS(board, 0, i);
        }

        for (int i = 0; i < n; ++i) {
            if (board[m - 1][i] == 'X' || board[m - 1][i] == 'U') continue;
            BFS(board, m - 1, i);
        }

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'X' || board[i][0] == 'U') continue;
            BFS(board, i, 0);
        }

        for (int i = 0; i < m; ++i) {
            if (board[i][n - 1] == 'X' || board[i][n - 1] == 'U') continue;
            BFS(board, i, n - 1);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') continue;
                else if (board[i][j] == 'U') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }

private:
    void BFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'U') {
            int m = board.size(), n = board[0].size();
            queue<pair<int, int>> q;
            q.push({i, j});
            board[i][j] = 'U';
            while (!q.empty()) {
                pair<int, int> coord = q.front();
                q.pop();
                int x = coord.first, y = coord.second;
                if (x < m - 1 && board[x + 1][y] == 'O') {
                    q.push({x + 1, y});
                    board[x + 1][y] = 'U';
                }

                if (x > 0 && board[x - 1][y] == 'O') {
                    q.push({x - 1, y});
                    board[x - 1][y] = 'U';
                }

                if (y < n - 1 && board[x][y + 1] == 'O') {
                    q.push({x, y + 1});
                    board[x][y + 1] = 'U';
                }

                if (y > 0 && board[x][y - 1] == 'O') {
                    q.push({x, y - 1});
                    board[x][y - 1] = 'U';
                }
            }
        }
    }
};
