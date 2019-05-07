/*
Given a list of strings, you need to find the longest uncommon subsequence 
among them. The longest uncommon subsequence is defined as the longest 
subsequence of one of these strings and this subsequence should not be any
subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting
some characters without changing the order of the remaining elements. Trivially,
any string is a subsequence of itself and an empty string is a subsequence of
any string.

The input will be a list of strings, and the output needs to be the length of
the longest uncommon subsequence. If the longest uncommon subsequence doesn't
exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
 */

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if (strs.empty()) return 0;
        sort(strs.begin(), strs.end(), [] (string& a, string& b) {
            return a.size() > b.size()});

    }
};

/*
遍历所有的字符串，对于每个遍历到的字符串，再和所有的其他的字符串比较，看是不是
某一个字符串的子序列，如果都不是的话，那么当前字符串就是一个非共同子序列，用其
长度来更新结果res

首先我们给字符串按长度来排序，将长度大的放到前面，这样我们如果找到了非共同子序列
，那么直接返回其长度即可，因为当前找到的肯定是最长的。然后我们用一个集合来记录
已经遍历过的字符串，利用集合的去重复特性，这样在有大量的重复字符串的时候可以提高
效率，然后我们开始遍历字符串，对于当前遍历到的字符串，我们和集合中的所有字符串
相比，看其是否是某个的子序列，如果都不是，说明当前的就是最长的非共同子序列。
注意如果当前的字符串是集合中某个字符串的子序列，那么直接break出来，不用再和其他
的比较了，这样在集合中有大量的字符串时可以提高效率，最后别忘了将遍历过的字符串加入集合中
 */

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        unordered_set<string> s;
        sort(strs.begin(), strs.end(), [](string a, string b){
            if (a.size() == b.size()) return a > b;
            return a.size() > b.size();
        });
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || strs[i] != strs[i + 1]) {
                bool found = true;
                for (auto a : s) {
                    int j = 0;
                    for (char c : a) {
                        if (c == strs[i][j]) ++j;
                        if (j == strs[i].size()) break;
                    }
                    if (j == strs[i].size()) {
                        found = false;
                        break;
                    }
                }
                if (found) return strs[i].size();
            }
            s.insert(strs[i]);
        }
        return -1;
    }
};
