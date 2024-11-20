class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> counts(3, -k);
        for (char c : s) counts[c-'a']++;
        for (int cnt : counts) {
            if (cnt < 0) return -1;
        }

        int res = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            counts[s[right] - 'a']--;
            while (counts[s[right] - 'a'] < 0) {
                counts[s[left++] - 'a']++;
            }
            res = max(res, right - left + 1);
        }

        return s.size() - res;
    }
};