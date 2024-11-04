// OOM solution
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        helper(nums, 0, m, k, res);
        return res;
    }

private:
    void helper(vector<int> &nums, int s, unordered_map<int, int> &m, int k, int &res) {
        if (s == nums.size()) {
            if (!m.empty()) res += 1;
            return;
        }

        helper(nums, s + 1, m, k, res);

        if (!m.count(nums[s] - k) && !m.count(nums[s] + k)) {
            m[nums[s]]++;
            helper(nums, s + 1, m, k, res);
            if (--m[nums[s]] == 0) m.erase(nums[s]);
        }
    }
};