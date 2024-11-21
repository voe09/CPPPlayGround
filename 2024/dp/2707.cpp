class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 100));
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        for (int i = 0; i < n; i++) {
            string ss = s.substr(i, 1);
            dp[i][i] = dict.count(ss) ? 0 : 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                string ss = s.substr(i, len);
                if (dict.count(ss)) {
                    dp[i][j] = 0;
                    continue;
                } else {
                    dp[i][j] = min(dp[i][j], len);
                }
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};