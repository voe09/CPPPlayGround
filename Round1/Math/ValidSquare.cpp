/*
Given the coordinates of four points in 2D space, return whether the four points
could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles
(90-degree angles).
Input points have no order.
 */
// 只有对角线和边两种长度
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> m;
        vector<vector<int>> v{p1, p2, p3, p4};
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int x1 = v[i][0], y1 = v[i][1], x2 = v[j][0], y2 = v[j][1];
                int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if (dist == 0) return false;
                ++m[dist];
            }
        }
        return m.size() == 2;
    }
};
