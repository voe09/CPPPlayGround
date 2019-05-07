/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
	if (s.empty() && p.empty()) return true;
	if (s.empty() || p.empty()) return false;
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;

	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (p[j - 1] != '*') {
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			} else {
				if (j > 1)
					dp[i][j] = dp[i][j - 2]
						|| (i > 0 && dp[i - 1][j] &&
							(s[i - 1] == p[j - 2] || p[j - 2] == '.'));
			}
		}
	}
	return dp[m][n];
}

int main() {
	cout << isMatch("aa", "a") << endl;
	cout << isMatch("aa","aa") << endl;
	cout << isMatch("aaa","aa") << endl;
	cout << isMatch("aa", "a*") << endl;
	cout << isMatch("aa", ".*") << endl;
	cout << isMatch("ab", ".*") << endl;
	cout << isMatch("aab", "c*a*b") << endl;
	cout << isMatch("aabb", "c*a*b") << endl;
}



bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i) {
        if (p[i - 1] == '*')
		dp[0][i] = dp[0][i - 2];
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (p[j - 1] != '*') {
				dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			} else {
				if (j > 1)
					dp[i][j] = dp[i][j - 2]
						|| (dp[i - 1][j] &&
							(s[i - 1] == p[j - 2] || p[j - 2] == '.'));
			}
		}
	}
	return dp[m][n];
}
