/*
Write a function that takes a string as input and 
reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
 */

class Solution {
public:
    string reverseVowels(string s) {
        int beg = 0, end = s.size() - 1;
        while (beg < end) {
            while (!isVowels(s[beg]) && beg < end) ++beg;
            while (!isVowels(s[end]) && beg < end) --end;
            if (beg < end) {
                std::swap(s[beg], s[end]);
                ++beg;
                --end;
            }
        }
        return s;
    }

private:
    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') return true;
        else if (c == 'A' || c == 'E' || c == 'I' ||
                 c == 'O' || c == 'U') return true;
        else return false;
    }
};
