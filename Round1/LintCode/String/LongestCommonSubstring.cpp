/*
Given two strings, find the longest common substring.

Return the length of it.

 Notice

The characters in substring should occur continuously in original string. This is different with subsequence.

Have you met this question in a real interview? Yes
Example
Given A = "ABCD", B = "CBCE", return 2.

Challenge 
O(n x m) time and memory.
 */

class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int n = A.size(), m = B.size();
        if (n == 0 || m == 0) return 0;
        vector<vector<int>> dp (n + 1, vector<int>(m + 1, 0));
        
        int maxVal = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        return maxVal;
    }
};
