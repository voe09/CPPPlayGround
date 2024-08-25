class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long res = LLONG_MIN;
        helper(nums, 0, 1, 0, res);
        return res;
    }

    void helper(vector<int>& nums, int i, long long curr, long long cnt, long long& res) {
        if (i >= nums.size()) {
            if (cnt > 0) res = max(curr, res);
            return;
        }

        helper(nums, i+1, curr, cnt, res);
        curr *= nums[i];
        helper(nums, i+1, curr, cnt+1, res);
    }
};