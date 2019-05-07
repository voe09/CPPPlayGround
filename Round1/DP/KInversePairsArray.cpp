/*
Given two integers n and k, find how many different arrays consist of numbers 
from 1 to n such that there are exactly k inverse pairs.

We define an inverse pair as following: For ith and jth element in the array, 
if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.

Since the answer may be very large, the answer should be modulo 109 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
Note:
The integer n is in the range [1, 1000] and k is in the range [0, 1000].
 */

// http://www.cnblogs.com/grandyang/p/7111385.html

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (n == 0) return 0;
        vector<vector<int>> dp (n, vector<int>(n, ));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }

        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < min(i, k + 1); ++j) {
                dp[i][j] = combination(i, j);
            }
        }

        return dp[n - 1][k];
    }

private:
    int combination(int n, int k) {
        int nom = 1;
        int dim = 1;
        for (int i = 1; i <= k; ++i) {
            nom *= n;
            dim *= i;
            --n;
        }
        return nom / dim;
    }
};


/*
dp[n+1][k]的含义，是1到n+1点数字中有k个翻转对的个数，那么实际上在1到n的数字中的某个位置加上了n+1这个数，为了简单起见，我们先让n=4，那么实际上相当于要在某个位置加上5，那么加5的位置就有如下几种情况：

xxxx5

xxx5x

xx5xx

x5xxx

5xxxx

这里xxxx表示1到4的任意排列，那么第一种情况xxxx5不会增加任何新的翻转对，
因为xxxx中没有比5大的数字，而 xxx5x会新增加1个翻转对，xx5xx，x5xxx，
5xxxx分别会增加2，3，4个翻转对。那么xxxx5就相当于dp[n][k]，即dp[4][k]，
那么依次往前类推，就是dp[n][k-1], dp[n][k-2]...dp[n][k-n]，
这样我们就可以得出dp[n+1][k]的求法了:

dp[n+1][k] = dp[n][k] + dp[n][k-1] + ... + dp[n][k - n]

那么dp[n][k]的求法也就一目了然了:

dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1]
 */

class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int m = 0; m <= k; ++m) {
                    if (m - j >= 0 && m - j <= k) {
                        dp[i][m] = (dp[i][m] + dp[i - 1][m - j]) % M;
                    }
                }
            }
        }
        return dp[n][k];
    }
};
