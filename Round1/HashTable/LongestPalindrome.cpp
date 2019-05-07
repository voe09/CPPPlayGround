/*
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (const auto &c: s) {
            ++map[c];
        }

        int res = 0;
        for (const auto &pair: map) {
            int carry = pair.second / 2;
            res += carry * 2;
        }
        if (res < static_cast<int>(s.size())) res += 1;
        return res;
    }
};
