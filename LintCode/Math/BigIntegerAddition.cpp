/*
Given two non-negative integers num1 and num2 represented as string, 
return the sum of num1 and num2.

Notice

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
Have you met this question in a real interview? Yes
Example
Given num1 = "123", num2 = "45"
return "168"
 */

class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        // write your code here
        string res;
        int m = num1.size() - 1, n = num2.size() - 1;
        int carry = 0;
        while (m >= 0 && n >= 0) {
            int sum = static_cast<int>(num1[m--] - '0')
                    + static_cast<int>(num2[n--] - '0') + carry;
            res += static_cast<char>('0' + sum % 10);
            carry = sum / 10;
        }

        while (m >= 0 || n >= 0) {
            int sum = (m >= 0) ? static_cast<int>(num1[m--] - '0')
                    : static_cast<int>(num2[n--] - '0');
            sum += carry;
            res += static_cast<char>('0' + sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) res += static_cast<char>('0' + carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
