/*
Given a non-empty string s, you may delete at most one character. 
Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int cnt = 0;
        while (left <= right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                if (s[left] == s[right - 1] &&
                    isPalindrome(s, left, right - 1)) return true;
                else if (s[left + 1] == s[right] &&
                    isPalindrome(s, left + 1, right)) return true;
                else return false;
            }
        }
        return true;
    }

private:
    bool isPalindrome(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
};
