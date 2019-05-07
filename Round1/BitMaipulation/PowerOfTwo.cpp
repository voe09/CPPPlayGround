/*
 * Given an integer, write a function to determine if it is a power of two.
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    }
};
