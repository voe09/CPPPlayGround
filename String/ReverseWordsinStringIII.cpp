/*
Given a string, you need to reverse the order of characters in each word within 
a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not 
be any extra space in the string.
*/

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        int length = s.size();
        int start = 0;
        for (int i = 0; i < length; ++i) {
            start = i;
            int end = start;
            while (s[end] != ' ' && end < length) {
                ++end;
                ++i;
            }
            std::reverse(s.begin() + start, s.begin() + end);
        }
        return s;
    }
};
