/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
 */

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        unordered_map<string, vector<string>> m;
        for (const auto &s : strs) {
            vector<int> cnts (26, 0);
            for (const auto &c : s) {
                ++cnts[c - 'a'];
            }
            string tmp;
            for (int i = 0; i < 26; ++i) {
                tmp += to_string(cnts[i]);
            }
            m[tmp].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto &pair : m) {
            res.push_back(pair.second);
        }
        return res;
    }
