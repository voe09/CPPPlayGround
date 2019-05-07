/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            --n;
            int tmp = n % 26;
            n /= 26;
            char letter = 'A' + tmp;
            res = res + letter;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
