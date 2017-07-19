/*
Given a string, find the first non-repeating character in it and return it's index.
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> lookup;

        for (int i = 0; i < s.size(); ++i) {
            if (lookup.count(s[i])) {
                lookup[s[i]].push_back(i);
            } else {
                lookup[s[i]] = {i};
            }
        }
        
        int length = s.size();
        int res = length + 1;
        for (const auto &pair: lookup) {
            if (pair.second.size() == 1) {
                res = min(res, pair.second[0]);
            }
        }
        if (res == length + 1) {
            return -1;
        } else {
            return res;
        }
    }
};
