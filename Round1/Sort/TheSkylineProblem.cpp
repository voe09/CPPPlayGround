/*
A city's skyline is the outer contour of the silhouette formed by all the 
buildings in that city when viewed from a distance. Now suppose you are given 
the locations and height of all the buildings as shown on a cityscape photo 
(Figure A), write a program to output the skyline formed by these 
buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of 
integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and 
right edge of the ith building, respectively, and Hi is its height. It is 
guaranteed that 0 ? Li, Ri ? INT_MAX, 0 < Hi ? INT_MAX, and Ri - Li > 0. 
You may assume all buildings are perfect rectangles grounded on an 
absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: 
[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of 
[ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 
A key point is the left endpoint of a horizontal line segment. Note that the 
last key point, where the rightmost building ends, is merely used to mark the 
termination of the skyline, and always has zero height. Also, the ground in 
between any two adjacent buildings should be considered part 
of the skyline contour.

For instance, the skyline in Figure B should be represented as:
[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed 
to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height 
in the output skyline. For instance, [...[2 3], [4 5], 
[7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 
5 should be merged into one in the final output as such: [...[2 3], [4 5], 
[12 7], ...]
 */

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        std::sort(buildings.begin(), buildings.end(), comp);

        vector<pair<int, int>> res;
        if (buildings.empty()) return res;
        pair<int, int> curr_corner{buildings[0][0], buildings[0][2]};
        int curr_L = buildings[0][0], curr_R = buildings[0][1], curr_H = buildings[0][2];
        for (int i = 1; i < buildings.size(); ++i) {
            if (buildings[i][0] == curr_L) {
                if (buildings[i][2] == curr_H)
                    continue;
                else {
                    
                }
            }
        }
    }

private:
    static bool comp(vector<int>& build1, vector<int>& build2) {
        if (build1[0] < build2[0]) return true;
        else if (build1[0] > build2[0]) return false;
        else {
            if (build1[2] > build2[2]) return true;
            else if (build1[2] < build2[2]) return false;
            else {
                if (build1[1] >= build[2]) return true;
                else return false;
            }
        }
    }
};

/*
要求的红点都跟每个小区间的左右区间点有密切的关系，而且进一步发现除了每一个封闭区
间的最右边的结束点是楼的右边界点，其余的都是左边界点，而且每个红点的纵坐标都是
当前重合处的最高楼的高度
用到了multiset数据结构，其好处在于其中的元素是按堆排好序的，插入新元素进去还是
有序的，而且执行删除元素也可方便的将所有相同的元素删掉。这里为了区分左右边界，
将左边界的高度存为负数，这样遇到左边界就存入堆中，遇到右边界就删掉，然后看当前
状态有无改变，改变了话就把左边界和当前的高度存入结果中 
 */
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);
            else m.erase(m.find(a.second));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
