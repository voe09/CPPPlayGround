/*
Given a string which consists of lowercase or uppercase letters, find the
length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

 Notice

Assume the length of given string will not exceed 1010.

Have you met this question in a real interview? Yes
Example
Given s = "abccccdd" return 7

One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        // write your code here
        unordered_map<char, int> m;
        for (const auto &c : s) {
            ++m[c];
        }

        int res = 0;
        for (const auto &pair : m) {
            if (pair.second % 2 == 0) res += pair.second;
            else {
                if (res % 2 == 0) res += pair.second;
                else res += (pair.second / 2) * 2;
            }
        }
        return res;
    }
};
