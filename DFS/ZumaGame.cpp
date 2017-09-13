/*
Think about Zuma Game. You have a row of balls on the table, colored red(R), 
yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row 
(including the leftmost place and rightmost place). Then, if there is a group 
of 3 or more balls in the same color touching, remove these balls. Keep doing 
this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table. 
If you cannot remove all the balls, output -1.

Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty 

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 

Note:
You may assume that the initial row of balls on the table won’t have any 3 or 
more consecutive balls with the same color.
The number of balls on the table won't exceed 20, and the string represents 
these balls is called "board" in the input.
The number of balls in your hand won't exceed 5, and the string represents 
these balls is called "hand" in the input.
Both input strings will be non-empty and only contain characters 
'R','Y','B','G','W'.
 */

class Solution {
public:
    int findMinStep(string board, string hand) {
        if (board.empty() || hand.empty()) return -1;
        vector<pair<char, int>> boards;
        unordered_map<char, int> hands;
        for (const auto& c : hand) {
            ++hands[c];
        }

        char prev = board[0];
        int cnt = 1;
        for (int i = 1; i < board.size(); ++i) {
            while (i < board.size() && board[i] == prev) {
                ++cnt;
                ++i;
            }
            if (i < board.size()) {
                boards.push_back({prev, cnt});
                prev = board[i];
                cnt = 1;
            }
        }

        boards.push_back({prev, cnt});
        int res = INT_MAX;
        int balls = 0;
        DFS(boards, hands, balls, res);
        return (res == INT_MAX) ? - 1 : res;
    }

private:
    void DFS(vector<pair<char, int>> board, unordered_map<char, int> hands,
            int balls, int& res) {
        RemoveBalls(board);


        if (board.empty()) {
            std::cout << balls << std::endl;
            res = min(balls, res);
            return;
        }
        if (hands.empty()) return;

        for (int i = 0; i < board.size(); ++i) {
            int need = 3 - board[i].second;
            if (hands.count(board[i].first) && hands[board[i].first] >= need) {
                vector<pair<char, int>> tmp = board;
                unordered_map<char, int> tmp_hand = hands;
                tmp[i].second += need;
                tmp_hand[board[i].first] -= need;
                if (tmp_hand[board[i].first] == 0) {
                    tmp_hand.erase(board[i].first);
                }
                DFS(tmp, tmp_hand, balls + need, res);
            }
        }
        return;
    }

    void RemoveBalls(vector<pair<char, int>>& board) {
        bool remove = false;
        do {
            remove = false;
            int i = 0;
            for (;i < board.size(); ++i) {
                if (board[i].second >= 3) {
                    remove = true;
                    break;
                }
            }

            if (remove) {
                board.erase(board.begin() + i);
                bool merge = false;
                do {
                    merge = false;
                    int j = 0;
                    int n = board.size();
                    for (;j < n - 1; ++j) {
                        if (board[j].first == board[j + 1].first) {
                            board[j + 1].second += board[j].second;
                            merge = true;
                            break;
                        }
                    }
                    if (merge) {
                        board.erase(board.begin() + j);
                    }
                } while (merge);
            }
        } while (remove);
    }
};
