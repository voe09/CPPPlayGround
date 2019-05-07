/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = 0;
        unordered_map<char, int> lookup;
        for (int i = 0; i < s.size(); ++i) {
            if (lookup.count(s[i]) == 0) {
                lookup[s[i]] = i;
            } else {
                int cnt = lookup.size();
                res = max(res, cnt);
                int end = lookup[s[i]];
                while (start <= end) {
                    lookup.erase(s[start]);
                    ++start;
                }
                lookup[s[i]] = i;
            }
        }
        int cnt = lookup.size();
        res = max(res, cnt);
        return res;
    }
};
