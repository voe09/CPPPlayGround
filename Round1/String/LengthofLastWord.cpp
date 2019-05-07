/*
Given a string s consists of upper/lower-case alphabets 
and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters 
only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int count = 0;
        int last_word = 0;
        int i = 0;
        for (;i < s.size(); ++i) {
            if (s[i] != ' ') ++count;
            else {
                last_word = count;
                while (s[i] == ' ') {
                    if (i == s.size() - 1) return last_word;
                    ++i;
                }
                count = 1;
            }
        }
        return count;
    }
};
