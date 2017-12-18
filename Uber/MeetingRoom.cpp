/*
Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 */

int NumOfRoom(vector<pair<int, int>> intervals) {
    if (intervals.empty()) return 0;
    vector<pair<int, bool>> times;
    for (const auto &interval : intervals) {
        times.push_back({interval.first, true});
        times.push_back({interval.second, false});
    }
    sort(times.begin(), times.end(), 
            [] (pair<int, bool> &a, pair<int, bool> &b) {
            return a.first < b.first;});

    int cnt = 0;
    stack<int> stk;
    for (const auto &time : times) {
        if (time.second) {
            stk.push(time.first);
            cnt = max(stk.size(), cnt);
        } else {
            stk.pop();
        }
    }
    return cnt;
}
