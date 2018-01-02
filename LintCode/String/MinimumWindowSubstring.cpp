/*
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

 Notice

If there is no such window in source that covers all characters in target, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.

Have you met this question in a real interview? Yes
Clarification
Should the characters in minimum window has the same order in target?

Not necessary.
Example
For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"

Challenge 
Can you do it in time complexity O(n) ?
 */

class Solution {
public:
    /*
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        unordered_map<char, int> m;
        string res;
        int cnt = 0;
        for (const auto &c : target) {
            ++m[c];
            ++cnt;
        }

        int left = 0, right = 0;
        int n = source.size();
        while (right < n) {
            while (cnt > 0) {
                if (m.count(source[right])) {
                    if (m[source[right]] > 0) {
                        --cnt;
                    }
                    --m[source[right++]];
                } else ++right;
            }

            while (cnt == 0) {
                if (m.count(source[left])) {
                    if (m[source[left]] >= 0) {
                        if (res.empty() || right - left < res.size()) {
                            res = source.substr(left - 1, right - left);
                        }
                        ++cnt;
                    }
                    ++m[source[left++]];
                } else ++left;
            }
        }
        return res;
    }
};
