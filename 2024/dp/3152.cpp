// out of mem
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                dp[i][j] = (dp[i][j-1] & ((nums[j-1] % 2) ^ (nums[j] % 2)));
            }
        }

        vector<bool> res;
        for (vector<int> &q : queries) {
            res.push_back(dp[q[0]][q[1]]);
        }

        return res;
    }
};


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i-1] % 2) {
                prefix[i] = prefix[i-1] + 1;
            } else {
                prefix[i] = prefix[i-1];
            }
        }

        vector<bool> res;
        for (vector<int> &q : queries) {
            bool isValid = prefix[q[1]] - prefix[q[0]] == 0;
            res.push_back(isValid);
        }

        return res;
    }
};