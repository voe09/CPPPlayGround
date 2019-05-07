/*
There are some trees, where each tree is represented by (x,y) coordinate in a 
two-dimensional garden. Your job is to fence the entire garden using the minimum
length of rope as it is expensive. The garden is well fenced only if all the trees
are enclosed. Your task is to help find the coordinates of trees which are exactly
located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees 
that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.
 */

// https://leetcode.com/articles/erect-the-fence/

/* Convex Hull
解法I Graham扫描法
1. Start with the left most point, l
2. Sorts all other points in counterclockwise order around l
   # That is: orient(l, l + 1) > 0 is always true for all points
3. Start with l, let p = l, q = l + 1, i + l + 1
4. Check orient(p, q, i):
    if < 0, move forward, let p = q, q = i, i = i + 1
    if > 0, remove q, let p = p - 1, q = o
5. Keep doing step 4, until all points have been checked
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
    vector<Point> outerTrees(vector<Point>& points) {
        if (points.size() <= 1)
            return points;
        Point bm = bottomLeft(points);
        sort(points.begin(), points.end(), [&](Point& p, Point& q) {
            int diff = orientation(bm, p, q) - orientation(bm, q, p);
            if (diff == 0) {
                int dist = distance(bm, p) - distance(bm, q);
                return dist > 0 ? true : false;
            } else
                return diff > 0 ? true : false;
        });

        int i = points.size() - 1;
        while (i >= 0 && orientation(bm, points[points.size() - 1], points[i]) == 0)
            --i;

        for (int l = i + 1, h = points.size() - 1; l < h; ++l, --h) {
            Point tmp = points[l];
            points[l] = points[h];
            points[h] = tmp;
        }
        stack<Point> stk;
        stk.push(points[0]);
        stk.push(points[1]);
        for (int j = 2; j < points.size(); ++j) {
            Point top = stk.top();
            stk.pop();
            while (orientation(stk.top(), top, points[j]) > 0) {
                top = stk.top();
                stk.pop();
            }
            stk.push(top);
            stk.push(points[j]);
        }
        
        vector<Point> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }

private:
    int orientation (Point& p, Point& q, Point& r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }

    int distance(Point& p, Point& q) {
        return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
    }

    Point bottomLeft(vector<Point>& points) {
        Point bottomLeft = points[0];

        for (const auto& p : points) {
            if (p.y < bottomLeft.y)
                bottomLeft = p;
        }

        return bottomLeft;
    }
};
