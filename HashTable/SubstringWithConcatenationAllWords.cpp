/*
You are given a string, s, and a list of words, words, that are all of the same 
length. Find all starting indices of substring(s) in s that is a concatenation 
of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int m = words.size();
        int n = words[0].size();
        int length = m * n;
        multimap<string, int> lookup;
        for (int i = 0; i < s.size() - length; ++i) {
            string tmp = s.substr(i, length);
            lookup.insert(std::make_pair(tmp, i));
        }

        vector<string> permutations;
        permutate(permutations, words, 0, m - 1);
        for (auto &concat_str: permutations) {
            if (lookup.count(concat_str) {
                for (it = lookup.equal_range(concat_str).first;
                     it != lookup.equal_range(concat_str).second; ++it) {
                    res.append(it->second);
                }
            }
        }
        return res;
    }

private:
    void permutate(vector<string> &vec, vector<string> &words,
                   int start, int end) {
        if (start == end) {
            string tmp;
            for (auto &word: words) {
                tmp = tmp + word;
            }
            vec.push_back(tmp);
        } else {
            for (int i = 0; i <= end - start; ++i) {
                std::swap(words[start], words[start + i]);
                permutate(vec, words, start + i + 1, end);
                std::swap(words[start], words[start + i]);
            }
        } 
    }
};



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const auto word_length = words.front().length();
        const auto cat_length = word_length * words.size();
        vector<int> result;

        if (s.length() < cat_length) {
            return result;
        }

        unordered_map<string, int> wordCount;
        for (const auto & word : words) {
            ++wordCount[word];
        }

        for (auto it = s.begin(); it != prev(s.end(), cat_length - 1); ++it) {
            unordered_map<string, int> unused(wordCount);
            for (auto jt = it; jt != next(it, cat_length); jt += word_length) {
                auto pos = unused.find(string(jt, next(jt, word_length)));
                if (pos == unused.end()) {
                    break;
                }
                if (--pos->second == 0) {
                    unused.erase(pos);
                }
            }
            if (unused.empty()) {
                result.emplace_back(distance(s.begin(), it));
            }
        }
        return result;
    }
};
