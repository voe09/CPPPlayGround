/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(string &s, int &i) {
        string res = "";
        int n = s.size();
        while (i < n && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                res += s[i++];
            } else {
                int cnt = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i++] - '0';
                }
                ++i;
                string t = decode(s, i);
                ++i;
                while (cnt-- > 0) {
                    res += t;
                }
            }
        }
        return res;
    }
};
