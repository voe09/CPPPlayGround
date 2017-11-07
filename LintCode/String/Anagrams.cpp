/*
Given an array of strings, return all groups of strings that are anagrams.

 Notice

All inputs will be in lower-case

Have you met this question in a real interview? Yes
Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

Challenge 
What is Anagram?
- Two strings are anagram if they can be the same after change the order of characters.
 */

class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> res;
        unordered_map<string, vector<string>> m;
        for (const auto &str : strs) {
            vector<int> counts (26, 0);
            for (const auto & c : str) {
                ++counts[static_cast<int>(c - 'a')];
            }
            string tmp = "";
            for (int i = 0; i < 26; ++i) {
                tmp += static_cast<char>('0' + counts[i]);
            }
            m[tmp].push_back(str);
        }

        for (const auto &pair : m) {
            if (pair.second.size() > 1) {
                for (const auto &word : pair.second) {
                    res.push_back(word);
                }
            }
        }
        return res;
    }
};
