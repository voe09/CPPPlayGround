/*
Given a string, determine if it is a palindrome, considering only alphanumeric 
characters and ignoring cases.

 Notice

Have you consider that the string might be empty? This is a good question to
ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Have you met this question in a real interview? Yes
Example
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Challenge 
O(n) time without extra memory.
 */

class Solution {
public:
    /*
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        if (s.empty()) return true;
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            while (left < right && !isAlphanumeric(s[left])) ++left;
            while (left < right && !isAlphanumeric(s[right])) --right;
            if (s[left] != s[right]) return false;
            ++left, --right;
        }
        return true;
    }

private:
    bool isAlphanumeric(char &c) {
        if (c >= 'A' && c <= 'Z') {
            int tmp = c - 'A';
            c = static_cast<char>(a' + tmp);
        }
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');
    }
};
