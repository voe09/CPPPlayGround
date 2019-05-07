/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval(int x, int y) : start(x), end(y) {}
};

vector<Interval> mergeIntervals(vector<Interval> &inters) {
    if (inters.empty()) return {};
    sort(inters.begin(), inters.end(), [] (Interval &a, Interval &b) {
        return a.start < b.start;
    });
    
    vector<Interval> res;
    for (const auto &interval : inters) {
        if (res.empty() || res.back().end < interval.start) {
            res.push_back(interval);
        }
        else {
            res.back().end = max(res.back().end, interval.end);
        }
    }
    return res;
}

int main() {
    vector<Interval> inputs {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = mergeIntervals(inputs);
    for (const auto &interval : res) {
        std::cout << interval.start << "," << interval.end << std::endl;
    }
}

// If is integers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval(int x, int y) : start(x), end(y) {}
};

vector<Interval> mergeIntervals(vector<Interval> &inters) {
    if (inters.empty()) return {};
    sort(inters.begin(), inters.end(), [] (Interval &a, Interval &b) {
        return a.start < b.start;
    });
    
    vector<Interval> res;
    for (const auto &interval : inters) {
        if (res.empty() || res.back().end < interval.start - 1) {
            res.push_back(interval);
        }
        else {
            res.back().end = max(res.back().end, interval.end);
        }
    }
    return res;
}

int main() {
    vector<Interval> inputs {{1, 3}, {2, 6}, {7, 10}, {15, 18}};
    auto res = mergeIntervals(inputs);
    for (const auto &interval : res) {
        std::cout << interval.start << "," << interval.end << std::endl;
    }
}
