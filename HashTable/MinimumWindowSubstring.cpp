/*
Given a string S and a string T, find the minimum window in S which will contain
all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the empty string "".

If there are multiple such windows, you are guaranteed that there will always 
be only one unique minimum window in S.
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int min_window_size = INT_MAX;
        string res = "";
        int str_size = t.size();
        unordered_map<char, int> T;
        for (auto &chara: t) {
            T[chara] = 0;
        }
        
        unordered_map<char, int> lookup;
        for (int i = 0; i < s.size(); ++i) {
            if (T.count(s[i])) {
                if (lookup.size() != str_size) {
                    lookup[s[i]] = i;
                    if (lookup.size() == str_size) {
                        WindowString(lookup, s, res, min_window_size);
                    }
                } else {
                    lookup[s[i]] = i;
                    WindowString(lookup, s, res, min_window_size);
                }
            }
        }
        return res;
    }

private:
    void WindowString(unordered_map<char, int> &lookup, string &s, 
                        string &res, int &min_window_size) {
        int min = INT_MAX;
        int max = INT_MIN;
        for (auto &pair: lookup) {
            if (pair.second < min) {
                min = pair.second;
            }
            if (pair.second > max) {
                max = pair.second;
            }
        }
        if (min_window_size > max - min + 1) {
            min_window_size = max - min + 1;
            res = s.substr(min, min_window_size);
        }
    }
};
