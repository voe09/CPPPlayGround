/*
Given A and B two interval lists, A has no overlap inside A and B has no overlap
inside B. Write the function to merge two interval lists, output the result with
no overlap. Ask for a very efficient solution

A naive method can combine the two list, and sort and apply merge interval in
the leetcode, but is not efficient enough.

For example,
A: [1,5], [10,14], [16,18]
B: [2,6], [8,10], [11,20]

output [1,6], [8, 20]
 */

class Interval {
    int begin;
    int end;
    Interval() {};
}

vector<Interval> mergeTwoIntervals(vector<Interval> &A, vector<Interval> &B) {
    if (A.empty() || B.empty()) return (A.empty()) ? B : A;
    int m = A.size(), n = B.size();
    int i = 0; j = 0;
    vector<Interval> res;
    while (i < m && j < n) {
        if (A[i].begin < B[j].begin()) {
            Interval &tmp = A[i];
            if (res.empty() || res.back().end < tmp.begin) {
                res.push_back(tmp);
            } else {
                res.back().end = max(res.back().end, tmp.end);
            }
            ++i;
        }
        else {
            Interval &tmp = B[j];
            if (res.empty() || res.back().end < tmp.begin) {
                res.push_back(tmp);
            } else {
                res.back().end = max(res.back().end, tmp.end);
            }
            ++j;
        }
    }

    while (i < m) {
        if (res.empty() || res.back().end < A[i].begin) {
            res.push_back(A[i]);
        } else {
            res.back().end = max(res.back().end, A[i].end);
        }
        ++i;
    }

    while (j < n) {
        if (res.empty() || res.back().end < B[j].begin) {
            res.push_back(B[j]);
        } else {
            res.back().end = max(res.back().end, tmp.end);
        }
        ++j;
    }
    return res;
}
