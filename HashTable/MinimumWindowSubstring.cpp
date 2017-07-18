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

// Wrong
class Solution {
public:
    string minWindow(string s, string t) {
        int min_window_size = INT_MAX;
        string res = "";
        int str_size = t.size();
        unordered_map<char, int> T;
        for (auto &chara: t) {
            T[chara] += 1;
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

    bool allFind(unordered_map<char, int> &T, 
            unordered_map<char, int> &lookup) {
        for (auto &pair: T) {
            if (lookup[pair.first] != pair.second) return false;
        }
        return true;
    }
};


class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) {
            if (m.find(T[i]) != m.end()) ++m[T[i]];
            else m[T[i]] = 1;
        }
        for (int right = 0; right < S.size(); ++right) {
            if (m.find(S[right]) != m.end()) {
                --m[S[right]];
                if (m[S[right]] >= 0) ++count;
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (m.find(S[left]) != m.end()) {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> T;
        string res = "";
        for (auto &chara: t) {
            T[chara] += 1;
        }

        int left = 0, right = 0, count = 0, minLen = s.size() + 1;
        for (;right < s.size(); ++right) {
            if (T.count(s[right])) {
                --T[s[right]];
                if (T[s[right]] >= 0) ++count;
                while (count == t.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = s.substr(left, minLen);
                    }
                    if (T.count(s[left])) {
                        ++T[s[left]];
                        if (T[s[left]] > 0) --count;
                    }
                    ++left;
                }
            } 
        }
        return res;
    }
};
