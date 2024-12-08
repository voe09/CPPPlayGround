class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string &s : strs) {
            m[transform(s)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &pair : m) res.push_back(pair.second);
        return res;
    }

    string transform(string &s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            cnts[c-'a']++;
        }
        string res;
        for (int cnt : cnts) {
            res.push_back('0' + cnt);
        }
        return res;
    }
};