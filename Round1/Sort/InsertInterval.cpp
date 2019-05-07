/*
Given a set of non-overlapping intervals, insert a new interval into the 
intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their 
start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) return vector<Interval>{newInterval};
        
        vector<Interval> res;
        int start = 0;
        for (; start < intervals.size(); ++start) {
            if (intervals[start].end >= newInterval.start) {
                if (intervals[start].start <= newInterval.end) {
                    newInterval.start = min(newInterval.start, intervals[start].start);
                    newInterval.end = max(newInterval.end, intervals[start].end);
                    break;
                } else {
                    res.push_back(newInterval);
                    while (start < intervals.size())
                        res.push_back(intervals[start++]);
                    return res;
                }
            }
            res.push_back(intervals[start]);
        }

        int end = start + 1;
        for (; end < intervals.size(); ++end) {
            if (intervals[end].start > newInterval.end) {
                res.push_back(newInterval);
                newInterval.start = 0;
                newInterval.end = -1;
                while (end < intervals.size()) {
                    res.push_back(intervals[end++]);
                }
            } else {
                newInterval.end = max(newInterval.end, intervals[end].end);
            }
        }
        if (newInterval.start <= newInterval.end) res.push_back(newInterval);
        return res;
    }
};
