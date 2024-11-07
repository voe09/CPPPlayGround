// backtracking TLE
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        int bitSum = INT_MAX;
        helper(candidates, 0, bitSum, 0, res);
        return res;
    }

private:
    void helper(vector<int> &nums, int i, int bitSum,  int cnt, int &res) {
        if (i == nums.size()) {
            res = max(res, cnt);
            return;
        }

        helper(nums, i+1, bitSum, cnt, res);
        if ((bitSum & nums[i]) > 0) {
            helper(nums, i+1, bitSum & nums[i], cnt+1, res);
        }
    }
};