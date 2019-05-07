/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Have you met this question in a real interview? Yes
Example
Given 4 points: (1,2), (3,6), (0,0), (1,3).

The maximum number is 3.
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /*
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        // write your code here
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate;
                    continue;
                }
                int diff_x = points[j].x - points[i].x;
                int diff_y = points[j].y - points[i].y;
                int div = gcd(diff_x, diff_y);
                ++m[(diff_x / div) ^ (diff_y / div)];
            }
            res = max(res, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }


private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
};
