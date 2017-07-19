/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the
given list, so that the concatenation of the two words, i.e. words[i] + words[j]
is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

// Wrong solution: only considering bat tab; not considering lls s.
// My correct implementation:
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> lookup;
        for (int i = 0; i < words.size(); ++i) {
            lookup[words[i]] = i;
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) {
            // if reverse words in lookup, add into res
            string word = words[i];
            std::reverse(word.begin(), word.end());
            if (lookup.count(word) && lookup[word] != i) {
                res.push_back({i, lookup[word]});
            }

            // if words is palindrome, add null string
            if (isPalindrome(word, 0, word.size() - 1)) {
                if (lookup.count("") && lookup[""] != i) {
                    res.push_back({i, lookup[""]});
                    res.push_back({lookup[""], i});
                }
            }

            for (int j = 1; j < words[i].size() - 1; ++j) {
                // Prefix
                if (j > 1 && isPalindrome(words[i], 0, j)) {
                    string prefix = words[i].substr(j + 1);
                    std::reverse(prefix.begin(), prefix.end());
                    if (lookup.count(prefix)) {
                        res.push_back({lookup[prefix], i});
                    }
                }
                // Suffix
                if (j < words[i].size() - 2 && isPalindrome(words[i], j, words[i].size() - 1)) {
                    string suffix = words[i].substr(0, j);
                    std::reverse(suffix.begin(), suffix.end());
                    if (lookup.count(suffix)) {
                        res.push_back({i, lookup[suffix]});
                    }
                }
            }
            return res;
        }
    }

private:
    bool isPalindrome(string &word, int start, int end) {
        while (start < end) {
            if (word[start++] != word[end--])
                return false;
        }
        return true;
    }
};



/*
利用字典wmap保存单词 -> 下标的键值对

遍历单词列表words，记当前单词为word，下标为idx：

1). 若当前单词word本身为回文，且words中存在空串，则将空串下标bidx与idx加入答案

2). 若当前单词的逆序串在words中，则将逆序串下标ridx与idx加入答案

3). 将当前单词word拆分为左右两半left，right。

     3.1) 若left为回文，并且right的逆序串在words中，则将right的逆序串下标rridx与idx加入答案
     
     3.2) 若right为回文，并且left的逆序串在words中，则将left的逆序串下标idx与rlidx加入答案
*/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> lookup;
        for (int i = 0; i < words.size(); ++i) {
            lookup[words[i]] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].length(); ++j) {
                if (is_palindrome(words[i], j, words[i].length() - 1)) {
                    string suffix = words[i].substr(0, j); 
                    reverse(suffix.begin(), suffix.end());
                    if (lookup.find(suffix) != lookup.end() && i != lookup[suffix]) {
                        res.push_back({i, lookup[suffix]});
                    }
                }
                if (j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if (lookup.find(prefix) != lookup.end() && lookup[prefix] != i) {
                        res.push_back({lookup[prefix], i});
                    }
                }
            }
        }
        return res;
    }

private:
    bool is_palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
