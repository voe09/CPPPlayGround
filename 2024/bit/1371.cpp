class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowels;
        vowels['a'] = 1;
        vowels['e'] = (1 << 1);
        vowels['i'] = (1 << 2);
        vowels['o'] = (1 << 3);
        vowels['u'] = (1 << 4);

        unordered_map<int, int> seens;
        seens[0] = -1;

        int mask = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (vowels.count(c)) {
                mask ^= vowels[c];
            }
            
            if (seens.count(mask)) {
                res = max(res, i - seens[mask]);
            } else {
                seens[mask] = i;
            }
        }
        return res;
    }
};