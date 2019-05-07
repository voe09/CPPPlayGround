/*
Given two binary strings, return their sum (also a binary string).

Have you met this question in a real interview? Yes
Example
a = 11
b = 1
Return 100
*/

class Solution {
public:
    /*
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        if (a.empty() || b.empty()) return a.empty() ? b : a;
        if (a.size() < b.size()) return addBinary(b, a);
        int p = a.size() - 1, q = b.size() - 1;
        string res;
        int carry = 0;
        while (p >= 0 && q >= 0) {
            int tmp = (a[p--] - '0') + (b[q--] - '0') + carry;
            carry = tmp / 2;
            tmp %= 2;
            res += to_string(tmp);
        }

        while (p >= 0) {
            int tmp = (a[p--] - '0') + carry;
            carry = tmp / 2;
            tmp %= 2;
            res += to_string(tmp);
        }

        if (carry != 0) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
