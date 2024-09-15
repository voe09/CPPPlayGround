class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, mx = 0, curr = 0;
        for (int num : nums) {
            if (mx < num) {
                mx = num;
                res = 0, curr = 0;
            }

            if (mx == num) {
                curr++;
            } else {
                curr = 0;
            }

            res = max(res, curr);
        }
        return res;
    }
};