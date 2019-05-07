/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.`
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        string tmp;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        int carry = 0;
        if (num1.size() >= num2.size()) {
            res = num1;
            tmp = num2;
        } else {
            res = num2;
            tmp = num1;
        }

        for (int i = 0; i < tmp.size(); ++i) {
            int val = res[i] - '0' + tmp[i] - '0' + carry;
            res[i] = val % 10 + '0';
            carry = val / 10;
        }

        if (carry != 0) {
            for (int i = tmp.size(); i < res.size(); ++i) {
                int val = res[i] - '0' + carry;
                res[i] = val % 10 + '0';
                carry = val / 10;
                if (carry == 0) break;
            }
        }

        if (carry != 0) res = res + "1";
        std::reverse(res.begin(), res.end());
        return res;
    }
};
