class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> &c = intervals[i];
            if (c[0] > res.back()[1]) res.push_back(c);
            else res.back()[1] = max(c[1], res.back()[1]);
        }
        return res;
    }
};