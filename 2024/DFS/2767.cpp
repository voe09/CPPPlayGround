class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int curr = 0;
        int res = INT_MAX;
        helper(s, 0, curr, 0, res);
        return res == INT_MAX ?  -1 : res;
    }

    void helper(string &s, int i, int curr, int cnt, int &res) {
        if (i >= s.size()) {
            if (curr == 0) res = min(res, cnt);
            return;
        }

        if (s[i] == '0' && curr == 0) return;

        curr = (curr << 1) + (s[i] - '0');
        if (isPowerFive(curr)) {
            helper(s, i + 1, 0, cnt+1, res);
        }
        helper(s, i+1, curr, cnt, res);
    }

    bool isPowerFive(int num) {
        while (num > 1) {
            if (num % 5 != 0) return false;
            num /= 5;
        }

        return num == 1;
    }
};