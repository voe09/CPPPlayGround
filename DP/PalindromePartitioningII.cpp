/*
Given a string s, partition s such that every substring of the partition is a
palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using
1 cut.
 */
/*
DP[i] = min (DP[j] + 1) ，对所有 0<=j<i，且s[j: i-1]为palindrome。
 */

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        vector<int> dp(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if ((j - i < 2 || palindrome[i + 1][j - 1]) && s[i] == s[j])
                    palindrome[i][j] = true;
            }
        }
        
        dp[0] = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (palindrome[j][i - 1])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n]; 
    }
};


class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n<=1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j])
                    isPal[i][j] = true;
            }
        }

        vector<int> dp(n+1,INT_MAX);
        dp[0] = -1;
        for(int i=1; i<=n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};
