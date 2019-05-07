/*
Given two words (start and end), and a dictionary, find all shortest 
transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
 Notice

All words have the same length.
All words contain only lowercase alphabetic characters.
Have you met this question in a real interview? Yes
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
 */

// TLE
class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end,
            unordered_set<string> &dict) {
        // write your code here
        vector<vector<string>> res;
        vector<string> curr;
        unordered_set<string> dict_set;
        for (const auto& word : dict) {
            dict_set.insert(word);
        }
        if (!dict_set.count(end)) return res;
        unordered_set<string> visited {start};
        curr.push_back(start);
        helper(start, end, dict_set, visited, curr, res);
        return res;
    }

private:
    void helper(string &start, string &end, unordered_set<string> &dict,
            unordered_set<string> &visited, vector<string> &curr, vector<vector<string>> &res) {
        if (curr.back() == end) {
            if (res.empty())
                res.push_back(curr);
            else {
                if (res.back().size() > curr.size()) {
                    res.clear();
                    res.push_back(curr);
                }
                else if (res.back().size() == curr.size()) {
                    res.push_back(curr);
                }
            }
            return;
        }

        for (int i = 0; i < start.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                char c = 'a' + j;
                string tmp = start;
                tmp[i] = c;
                if (dict.count(tmp) && !visited.count(tmp)) {
                    curr.push_back(tmp);
                    visited.insert(tmp);
                    helper(tmp, end, dict, visited, curr, res);
                    visited.erase(tmp);
                    curr.pop_back();
                }
            }
        }
    }
};
