/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication.
Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
 */

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream tmp1(a);
        istringstream tmp2(b);
        int real, img;
        char op, img_op;
        tmp1 >> real >> op >> img >> img_op;
        pair<int, int> num1 {real, img};
        tmp2 >> real >> op >> img >> img_op;
        pair<int, int> num2 {real, img};

        real = num1.first * num2.first - num1.second * num2.second;
        img = num1.first * num2.second + num1.second * num2.first;
        return to_string(real) + "+" + to_string(img) + "i";
    }
};
