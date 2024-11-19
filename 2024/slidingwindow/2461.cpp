class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long res = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                if (--m[nums[i-k]] == 0) m.erase(nums[i-k]);
                sum -= nums[i-k];
            }
            m[nums[i]]++;
            sum += nums[i];
            if (m.size() == k) {
                res = max(res, sum);
            }
        }

        return res;
    }
};