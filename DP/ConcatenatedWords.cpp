/*
Given a list of words (without duplicates), please write a program that returns
all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at 
least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
 */

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() <= 2) return {};
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for (const auto word : words) {
            dict.erase(word);
            if (word.empty()) continue;
            int length = word.size();
            vector<bool> dp(length + 1, false);
            dp[0] = true;
            for (int i = 1; i <= length; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (dp[j] && dict.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[length]) res.push_back(word);
            dict.insert(word);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() <= 2) return {};
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            dict.erase(word);
            int len = word.size();
            if (len == 0) continue;
            vector<bool> v(len + 1, false);
            v[0] = true;
            for (int i = 0; i < len + 1; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (v[j] && dict.count(word.substr(j, i - j))) {
                        v[i] = true;
                        break;
                    }
                }
            }
            if (v.back()) res.push_back(word);
            dict.insert(word);
        }
        return res;
    }
};
