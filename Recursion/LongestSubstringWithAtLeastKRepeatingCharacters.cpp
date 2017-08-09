/*
Find the length of the longest substring T of a given string (consists of
lowercase letters only) such that every character in T appears no less 
than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 
'b' is repeated 3 times.
 */

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.size();
        while (i + k <= n) {
            vector<int> lookup(26, 0);
            int mask = 0, max_idx = i;
            for (int j = i; j < n; ++j) {
                ++lookup[s[j] - 'a'];
                if (lookup[s[j] - 'a'] >= k)
                    mask &= (~(1 << (s[j] - 'a')));
                else
                    mask |= (1 << (s[j] - 'a'));
                if (mask == 0) {
                    res = max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
        }
        return res;
    }
};


// Recursive version
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), max_idx = 0, res = 0;
        int m[128] = {0};
        bool ok = true;
        for (char c : s) ++m[c];
        for (int i = 0; i < n; ++i) {
            if (m[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(max_idx, i - max_idx), k));
                ok = false;
                max_idx = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(max_idx, n - max_idx), k));
    }
};
