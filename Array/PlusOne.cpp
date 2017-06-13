/*
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int digit = digits[i] + carry;
            carry = digit / 10;
            digit = digit % 10;
            digits[i] = digit;
        }

        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
