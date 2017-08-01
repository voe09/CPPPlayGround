/*
 * Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */

class Solution {
public:
    string reverseString(string s) {
        int length = s.size();
        int begin = 0, end = length - 1;
        while (begin < end) {
            std::swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};
