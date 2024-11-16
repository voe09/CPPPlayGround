class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1, -1);
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.empty() || nums[q.back()] == nums[i] - 1) q.push_back(i);
            else {
                q.clear();
                q.push_back(i);
            }

            if (q.size() == k) {
                res[q.front()] = nums[q.back()];
                q.pop_front();
            }
        }

        return res;
    }
};