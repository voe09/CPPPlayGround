/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> partitions;
        DFS(s, 0, partitions, res);
        return res;
    }

private:
    void DFS(string& s, int start, vector<string>& partitions,
            vector<vector<string>>& res) {
        if (start >= s.size()) {
            res.push_back(partitions);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isValid(s, start, i)) {
                partitions.push_back(s.substr(start, i - start + 1));
                DFS(s, i + 1, partitions, res);
                partitions.pop_back();
            }
        }
    }

    bool isValid(string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};
