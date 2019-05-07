/*
Given two strings S and T, determine if they are both one edit distance apart.

Have you met this question in a real interview? Yes
Example
Given s = "aDb", t = "adb"
return true
 */

class Solution {
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        if (s.size() < t.size()) swap(s, t);
        int m = s.size(), n = t.size();
        if (abs(m - n) >= 2) return false;
        if (m == n) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (s[i] != t[i]) ++cnt;
            }
            return cnt == 1;
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
            return true;
        }
        return false;
    }
};
