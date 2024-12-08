class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int l = 0, res = 0;
        for (int r = 0; r < s.size(); r++) {
            while (m.count(s[r])) {
                m.erase(s[l++]);
            }
            m.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};