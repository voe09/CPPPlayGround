/*
Given n points on a 2D plane, find the maximum number of points that lie on 
the same straight line.
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

/*
For each point p, calculate its slope with other points and use a map to record
how many points have same slope, by which we can find out how many points are 
on same line with p as their one point. For each point keep doing the same thing
and update the maximum number of point count found so far.

1) if two point are (x1, y1) and (x2, y2) then their slope will be (y2 – y1) / (x2 – x1) 
which can be a double value and can cause precision problems. 
To get rid of the precision problems, we treat slope as pair 
((y2 – y1), (x2 – x1)) instead of ratio and reduce pair by their gcd 
before inserting into map. In below code points which are vertical or 
repeated are treated separately.

2) If we use unordered_map in c++ or HashMap in Java for storing the slope 
pair, then total time complexity of solution will be O(n^2)
 */

// Problem of above idea, unordered_map do not have default hash function for pair
// as a key

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slope_count;
            const auto& start = points[i];
            int same = 1;

            for (int j = i + 1; j < points.size(); ++j) {
                const auto& end = points[j];
                if (start.x == end.x && start.y == end.y) {
                    ++same;
                } else {
                    auto slope = numeric_limits<double>::max();
                    if (start.x - end.x != 0) {
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x);
                    }
                    ++slope_count[slope];
                }
            }

            int current_max = same;
            for (const auto& kvp : slope_count) {
                current_max = max(current_max, kvp.second + same);
            }
            max_points = max(max_points, current_max);
        }

        return max_points;
    }
};
