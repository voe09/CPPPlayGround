/*
Given a string, determine if it is a palindrome, considering only alphanumeric 
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) {
                s[idx] = s[i];
                if (isalpha(s[idx]) && isupper(s[idx])) s[idx] = tolower(s[idx]);
                ++idx;
            }
        }
        int left = 0, right = idx - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
