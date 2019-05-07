/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains 
lowercase letters separated by a single space.
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        set<string> str_set;
        unordered_map<char, string> map;
        int idx = 0;
        for (int i = 0; i < str.size(); ++i) {
            string tmp = "";
            while (i < str.size() && str[i] != ' ') {
                tmp = tmp + str[i++];
            }
            if (map.count(pattern[idx]) == 0) {
                if (str_set.count(tmp) == 0) {
                    map[pattern[idx]] = tmp;
                    str_set.insert(tmp);
                } else {
                    return false;
                }
            } else {
                if (map[pattern[idx]] != tmp) return false;
            }
            ++idx;
        }
        int length = pattern.size();
        if (idx != length) return false;
        return true;
    }
};
