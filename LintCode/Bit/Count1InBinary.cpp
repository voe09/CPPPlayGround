/*
Count how many 1 in binary representation of a 32-bit integer.

Have you met this question in a real interview? Yes
Example
Given 32, return 1

Given 5, return 2

Given 1023, return 9

Challenge 
If the integer is n bits with m 1 bits. Can you do it in O(m) time?
 */
/*
num－1可以将最低位的1变为0，然后和num取&操作将num中最低位的1删去并将剩下的1
保留下来，如此重复直到num中的1全部变为0，变换的次数即为num中1的个数。
 */
class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int cnt = 0;
        while (num) {
            if (num & 1) ++cnt;
            num >>= 1;
        }
        return cnt;
    }
};

class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int cnt = 0;
        while (num) {
            num = num & (num - 1);
            ++cnt;
        }
        return cnt;
    }
};
