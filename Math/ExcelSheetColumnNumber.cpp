/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            int tmp = s[i] - 'A';
            ++tmp;
            res += tmp * pow(26, length - i - 1);
        }
        return res;
    }
};
