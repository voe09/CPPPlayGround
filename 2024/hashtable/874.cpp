class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> obs;
        for (vector<int>& obstacle: obstacles) obs[obstacle[0]].insert(obstacle[1]);

        int res = 0;
        int x = 0, y = 0;
        pair<int, int> dir = make_pair(0, 1);
        for (int cmd : commands) {
            if (cmd == -2) dir = make_pair(-dir.second, dir.first);
            if (cmd == -1) dir = make_pair(dir.second, -dir.first);
            else if (cmd >= 1 && cmd <= 9) {
                for (int k = 1; k <= cmd; k++) {
                    int x_next = x + dir.first, y_next = y + dir.second;
                    if (obs.count(x_next) && obs[x_next].count(y_next)) break;
                    x = x_next, y = y_next;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }

/*
turn left: (x, y) -> (-y, x)
turn right: (x, y) -> (y, -x)
*/
};