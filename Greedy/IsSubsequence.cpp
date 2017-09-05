/*
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. 
t is potentially a very long (length ~= 500,000) string, and s is a 
short string (<=100).

A subsequence of a string is a new string which is formed from the original 
string by deleting some (can be none) of the characters without disturbing 
the relative positions of the remaining characters. (ie, "ace" is a subsequence
of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you 
want to check one by one to see if T has its subsequence. In this scenario, 
how would you change your code?
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool isSub = true;
        int i = 0, j = 0;
        int m = s.size(), n = t.size();
        while (j < n) {
            while (j < n && s[i] != t[j]) {
                ++j;
            }
            if (i == m - 1 && j < n)
                return true;
            ++i;
            ++j;
        }
        return false;
    }
};

// https://discuss.leetcode.com/topic/58078/simple-c-code-as-well-as-the-followup-solution
class Solution {
public:
    Solution(string t):target(t) {
        for(int i = 0; i < t.length(); ++i) {
            posMap[t[i] - 'a'].push_back(i);
        }
    }
    
    vector<bool> isSubsequence(vector<string> strs) {
        int pre = -1;
        int index[26];
        vector<bool> ans;
        for(string str: strs) {
            memset(index, -1, sizeof(index));
            pre = -1;
            int i = 0;
            for(;i < str.size(); ++i) {
                int j = str[i] - 'a';
                if(posMap.find(j) == posMap.end() || posMap[j].size()<= index[j] + 1 || posMap[j][index[j] + 1] <= pre) {
                    ans.push_back(false);
                    break;
                }
                pre = posMap[j][index[j] + 1];
                index[j]++;
            }
            if(i == str.size()) ans.push_back(true);
        }
        return ans;
    }
    
private:
    string target;
    unordered_map<int, vector<int> > posMap;
};
