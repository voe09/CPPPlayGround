/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
    vector<Interval> merge(vector<Interval>& intervals) {
        int length = intervals.size();
        if (length == 0) return intervals;
        iter beg = intervals.begin(), end = intervals.begin() + length - 1;
        return merge(beg, end);
    }

private:
    typedef vector<Interval>::iterator iter;
    vector<Interval> merge(iter& begin, iter& end) {
        int length = end - begin;
        if (length == 0) return vector<Interval>(begin, end + 1);
        iter left_ptr = begin + length / 2;
        iter right_ptr = left_ptr + 1;
        vector<Interval> left = merge(begin, left_ptr);
        vector<Interval> right = merge(right_ptr, end);
        // merge left and right
        vector<Interval> res;
        int i = 0, j = 0;
        Interval tmp;
        while (i < left.size() && j < right.size()) {
            // if overlap, merge to one
            if (tmp.start == 0 && tmp.end == 0) {
                if (compareInterval(left[i], right[j]))
                    tmp = left[i++];
                else
                    tmp = right[j++];
            } else {
                if (compareInterval(left[i], right[j])) {
                    if (left[i].start <= tmp.end) {
                        if (tmp.end < left[i].end)
                            tmp.end = left[i++].end;
                        else ++i;
                    }
                    else {
                        res.push_back(tmp);
                        tmp = left[i++];
                    }
                }
                else {
                    if (right[j].start <= tmp.end) {
                        if (tmp.end < right[j].end)
                            tmp.end = right[j++].end;
                        else ++j;
                    }
                    else {
                        res.push_back(tmp);
                        tmp = right[j++];
                    }
                }
            }
        }

        if (i < left.size()) {
            while (left[i].start <= tmp.end) {
                if (tmp.end < left[i].end)
                    tmp.end = left[i++].end;
                else ++i;
            }
            res.push_back(tmp);
            while (i < left.size())
                res.push_back(left[i++]);
        }
        if (j < right.size()) {
            while (right[j].start <= tmp.end) {
                if (tmp.end < right[j].end)
                    tmp.end = right[j++].end;
                else ++j;
            res.push_back(tmp);
            while (j < right.size())
                res.push_back(right[j++]);
            }
        }
        return res;
    }

private:
    bool compareInterval(Interval& left, Interval& right) {
        if (left.start < right.start) return true;
        else if (left.start > right.start) return false;
        else {
            if (left.end <= right.end) return true;
            else return false;
        }
    }
};


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });

        vector<Interval> result{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= result.back().end) {
                result.back().end = max(result.back().end, intervals[i].end);
            } else {
                result.emplace_back(intervals[i]);
            }
        }

        return result;
    }
};
