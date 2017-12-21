/*
Given a non-negative integer num, repeatedly add all its digits until
the result has only one digit.

Have you met this question in a real interview? Yes
Example
Given num = 38.
The process is like: 3 + 8 = 11, 1 + 1 = 2. 
Since 2 has only one digit, return 2.

Challenge 
Could you do it without any loop/recursion in O(1) runtime?
 */

class Solution {
public:
    /*
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        // write your code here
        if (num < 10) return num;
        int res = 0;
        while (num > 0) {
            res += (num % 10);
            num /= 10;
        }
        return addDigits(res);
    }
};
