/*
Given two words (beginWord and endWord), and a dictionary's word list,
find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not
a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set
of strings). Please reload the code definition to get the latest changes.
 */

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        vector<string> ladder;
        if (!words.count(endWord)) return {};
        ladder.push_back(beginWord);
        DFS(words, endWord, ladder, res);
        return res;
    }

private:
    void DFS(unordered_set<string>& words, string& endWord,
            vector<string>& ladder, vector<vector<string>>& res) {
        if (!res.empty() && res.back().size() < ladder.size()) return;
        if (ladder.back() == endWord) {
            while (!res.empty() && res.back().size() > ladder.size()) {
                res.pop_back();
            }
            res.push_back(ladder);
            return;
        }

        if (words.empty()) return;
        
        string curWord = ladder.back();
        for (int i = 0; i < curWord.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                string tmp = curWord;
                tmp[i] = c;
                if (words.count(tmp)) {
                    ladder.push_back(tmp);
                    words.erase(tmp);
                    DFS(words, endWord, ladder, res);
                    words.insert(tmp);
                    ladder.pop_back();
                }
            }
        }
    }
};


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front(); paths.pop();
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};
