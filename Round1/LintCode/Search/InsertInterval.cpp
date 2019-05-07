/*
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and 
non-overlapping (merge intervals if necessary).

Have you met this question in a real interview? Yes
Example
Insert [2, 5] into [[1,2], [5,9]], we get [[1,9]].

Insert [3, 4] into [[1,2], [5,9]], we get [[1,2], [3,4], [5,9]].
 */

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        if (intervals.empty()) return (intervals.push_back(newInterval));
        int left = 0, right = intervals.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid].start >= newInterval.end) left = mid + 1;
            else
                right = mid - 1;
        }
        vector<Interval> res;
        for (int i = 0; i <= right; ++i) {
            res.push_back(intervals[i]);
        }
        
        if (!res.empty()) {
            if (res.back().end < newInterval.start) {
                res.push_back(newInterval);
            } else {
                res.back().end = newinterval.end;
            }
        } else {
            res.push_back(newInterval);
        }

        if (res.back().end < intervals[left].start) {
            res.push_back(intervals[left]);
        } else {
            res.back().end = intervals[left].end;
        }

        for (int i = left + 1; i < intervals.size(); ++i) {
            res.push_back(intervals[i]);
        }

        return intervals;
    }
};
