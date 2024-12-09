class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());

        int mxVal = 0, mxSum = 0;
        for (vector<int> &event : events) {
            while (!pq.empty() && pq.top().first < event[0]) {
                mxVal = max(mxVal, pq.top().second);
                pq.pop();
            }
            mxSum = max(mxSum, mxVal + event[2]);
            pq.push({event[1], event[2]});
        }
        return mxSum;
    }
};

// mem ooo
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());

        int mxVal = 0, mxSum = 0;
        for (vector<int> &event : events) {
            while (!pq.empty() && pq.top().first < event[0]) {
                mxVal = max(mxVal, pq.top().second);
                pq.pop();
            }
            mxSum = max(mxSum, mxVal + event[2]);
            pq.push({event[1], event[2]});
        }
        return mxSum;
    }
};