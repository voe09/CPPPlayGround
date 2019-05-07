/*
Check a positive number is a palindrome or not.

A palindrome number is that if you reverse the whole number you will get exactly the same number.

 Notice

It's guaranteed the input number is a 32-bit integer, but after reversion, the number may exceed the 32-bit integer.

Have you met this question in a real interview? Yes
Example
11, 121, 1, 12321 are palindrome numbers.

23, 32, 1232 are not palindrome numbers.
 */

class Solution {
public:
    /*
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        int div = 1;
        while (num / div >= 10) {
            div *= 10;
        }

        while (num) {
            int left = num / div;
            int right = num % 10;
            if (left != right) return false;
            num -= left * div;
            num /= 10;
            div /= 100;
        }

        return true;
    }
};
