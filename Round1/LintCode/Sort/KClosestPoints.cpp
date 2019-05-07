/*
Given some points and a point origin in two dimensional space, find k points 
out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance, sorted
by x-axis, otherwise sorted by y-axis.

Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]
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

Point originPoint;

int calDistance(Point &a) {
    return (a.x - originPoint.x) * (a.x - originPoint.x)
        + (a.y - originPoint.y) * (a.y - originPoint.y);
}

class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        originPoint = origin;
        priority_queue<Point, vector<Point>, CompPoint> q;
        for (auto &point : points) {
            q.push(point);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<Point> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    struct CompPoint { 
        bool operator() (Point &a, Point &b) {
            int dist_a = calDistance(a);
            int dist_b = calDistance(b);
            if (dist_a == dist_b) {
                if (abs(a.x) == abs(a.y))
                    return abs(a.y) < abs(b.y);
                else
                    return abs(a.x) < abs(b.x);
            } else {
                return dist_a < dist_b;
            }
        }
    };
};
