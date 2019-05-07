/*
Given N axis-aligned rectangles where N > 0, determine if they all together 
form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. 
For example, a unit square is represented as [1,1,2,2]. (coordinate of 
bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
 */

// http://www.cnblogs.com/grandyang/p/5825619.html

/*
 * 错误做法
 */
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return true;
        pair<int, int> btm_left(rectangles[0][0], rectangles[0][1]),
            top_right(rectangles[0][2], rectangles[0][3]);
        int area = 0;
        for (int i = 0; i < rectangles.size(); ++i) {
            vector<int> &rectangle = rectangles[i];
            area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            if (rectangle[0] * rectangle[1] < btm_left.first * btm_left.second) {
                btm_left.first = rectangle[0];
                btm_left.second = rectangle[1];
            }
            if (rectangle[2] * rectangle[3] > top_right.first * top_right.second) {
                top_right.first = rectangle[2];
                top_right.second = rectangle[3];
            }
        }
        int sum = (top_right.first - btm_left.first) * (top_right.second - btm_left.second);
        if (area != sum) return false;
        return true;
    }
};

/*
 * 每个绿点其实都是两个顶点的重合，每个红点都是四个顶点的重合，而每个蓝点只有一个顶点，有了这条神奇的性质就不用再去判断“每个点最多只能是一个矩形的左下，左上，右上，或右下顶点”这条性质了，我们直接用一个set，对于遍历到的任意一个顶点，如果set中已经存在了，则删去这个点，如果没有就加上，这样最后会把绿点和红点都滤去，剩下的都是蓝点，我们只要看蓝点的个数是否为四个，再加上检测每个矩形面积累加和要等于最后的大矩形的面积即可，参见代码如下：
 */

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> st;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, area = 0;
        for (auto rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            string s1 = to_string(rect[0]) + "_" + to_string(rect[1]); // bottom-left
            string s2 = to_string(rect[0]) + "_" + to_string(rect[3]); // top-left
            string s3 = to_string(rect[2]) + "_" + to_string(rect[3]); // top-right
            string s4 = to_string(rect[2]) + "_" + to_string(rect[1]); // bottom-right
            if (st.count(s1)) st.erase(s1);
            else st.insert(s1);
            if (st.count(s2)) st.erase(s2);
            else st.insert(s2);
            if (st.count(s3)) st.erase(s3);
            else st.insert(s3);
            if (st.count(s4)) st.erase(s4);
            else st.insert(s4);
        }
        string t1 = to_string(min_x) + "_" + to_string(min_y);
        string t2 = to_string(min_x) + "_" + to_string(max_y);
        string t3 = to_string(max_x) + "_" + to_string(max_y);
        string t4 = to_string(max_x) + "_" + to_string(min_y);
        if (!st.count(t1) || !st.count(t2) || !st.count(t3) || !st.count(t4) || st.size() != 4) return false;
        return area == (max_x - min_x) * (max_y - min_y);
    }
};

