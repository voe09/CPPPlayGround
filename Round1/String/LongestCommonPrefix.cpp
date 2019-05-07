/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;
        int len = numeric_limits<int>::max();
        for (int i = 0; i < strs.size(); ++i) {
            if (len > strs[i].size())
                len = strs[i].size();
        }

        for (int size = 1; size <= len; ++size) {
            string common;
            common = strs[0][size - 1];
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][size - 1] != strs[0][size - 1])
                    return res;
            }
            res += strs[0][size - 1];
        }

        return res;
    }
};
