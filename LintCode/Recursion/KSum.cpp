/*
Given n distinct positive integers, integer k (k <= n) and a number target.

Find k numbers where sum is target. Calculate how many solutions there are?

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4], k = 2, target = 5.

There are 2 solutions: [1,4] and [2,3].

Return 2.
 */

// TLE
class Solution {
public:
    /*
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        int res = 0;
        if (k <= 0) return res;
        if (k == 1) {
            for (const auto &num : A) {
                if (num == target) ++res;
            }
            return res;
        }
        sort(A.begin(), A.end());
        kSum(A, k, target, 0, res);
        return res;
    }

private:
    void kSum(vector<int> &A, int k, int target, int start, int &res) {
        if (k == 2) {
            int left = start, right = A.size() - 1;
            while (left < right) {
                if (A[left] + A[right] == target) {
                    ++res;
                    ++left, --right;
                } else if (A[left] + A[right] > target) {
                    --right;
                } else {
                    ++left;
                }
            }
            return;
        } else {
            for (int i = start; i < A.size(); ++i) {
                kSum(A, k - 1, target - A[i], i + 1, res);
            }
        }
    }
};


/*
用三维动态规划。
ksum[i][j][l]表示前j个元素里面取l个元素之和为i。
初始化：ksum[0][j][0] =1(j:0~n)，即前j个元素里面取0个元素使其和为0的方法只有1种，
那就是什么都不取+

状态函数：
ksum[i][j][l]=ksum[i][j-1][l]+ksum[i-A[i-1]][j-1][l-1]
即前j个元素里面取l个元素之和为i由两种情况组成：第一种情况为不包含第i个元素，
即前j－1个元素里取l个元素使其和为i，第二种情况为包含第i个元素，即前j－1个
元素里取l－1个元素使其和为i-A[i-1]（前提是i-A[i-1]>=0）。
 */

class Solution {
public:
    /*
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        int n = A.size();
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(n + 1, vector<int>(k + 1)));
        for (int i = 0; i <= n; ++i) dp[0][i][0] = 1;

        for (int t = 1; t<= target; ++t) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    dp[t][i][j] = dp[t][i - 1][j];
                    if (t >= A[i - 1]) dp[t][i][j] += dp[t - A[i - 1]][i - 1][j - 1];
                }
            }
        }
        return dp[target][n][k];
    }
};


