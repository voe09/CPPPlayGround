class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        string res{s[0]};
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (s[i] != s[j]) continue;
                if (gap == 1) dp[i][j] = true;
                else dp[i][j] = dp[i+1][j-1];
                if (dp[i][j] && gap + 1 > res.size()) res = s.substr(i, gap + 1); 
            }
        }
        return res;
    }
};