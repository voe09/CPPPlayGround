/*
 * Given an integer (signed 32 bits), write a function to check 
 * whether it is a power of 4.
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 * Follow up: Could you solve it without loops/recursion?
 * Credits:
 * Special thanks to @yukuairoy for adding this problem and creating all test cases.
 */

// http://www.cnblogs.com/grandyang/p/5403783.html

class Solution {
public:
    bool isPowerOfFour(int num) {
        int cnt = 0;
        int even = true;
        int i = 0;
        while (num > 0) {
            if (num & 1) {
                if (i % 2 != 0)
                    even = false;
                cnt += 1;
            }
            num >>= 1;
        }
        return (cnt == 1) && even;
    }
};
