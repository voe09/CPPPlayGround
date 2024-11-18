// mono queue
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int, long>> dq;
        dq.push_back({-1, 0});
        long sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (!dq.empty() && sum - dq.front().second >= k) {
                pair<int, int> t = dq.front();
                dq.pop_front();
                res = min(res, i - t.first);
            }

            while (!dq.empty() && sum <= dq.back().second) {
                dq.pop_back();
            }

            dq.push_back({i, sum});
        }

        return res == INT_MAX ?  -1 : res;
    }
};