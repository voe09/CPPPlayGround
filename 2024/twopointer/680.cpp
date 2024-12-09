class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) l++, r--;
            else return isValid(s, l, r-1) || isValid(s, l+1, r);
        }

        return true;
    }

    bool isValid(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};