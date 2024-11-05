// TLE solution
class Solution {
public:
    int minChanges(string s) {
        if (s.size() == 2) {
            return s[0] == s[1] ? 0 : 1;
        }
        if (m.count(s)) return m[s];

        int res = INT_MAX;
        for (int i = 2; i < s.size(); i += 2) {
            res = min(res, minChanges(s.substr(0, i)) + minChanges(s.substr(i)));
        }

        m[s] = res;
        return res;
    }

private:
    map<string, int> m;
};


// TLE 2
class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < s.size() - 1; i += 2) {
            dp[i][i+1] = (s[i] == s[i+1] ? 0 : 1);
        }

        for (int len = 4; len <= s.size(); len += 2) {
            for (int i = 0; i <= s.size() - len; i += 2) {
                int j = i + len - 1;
                for (int k = i + 2; k < j; k += 2) {
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};


class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];
        
        int cnt = 0, minChanges = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == curr) {
                cnt++;
                continue;
            }

            if (cnt % 2 == 0) {
                cnt = 1;
            } else {
                cnt = 0;
                minChanges++;
            }

            curr = s[i];
        }

        return minChanges;
    }
};