/*
 * Reverse bits of a given 32 bits unsigned integer.
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * Related problem: Reverse Integer
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 1) {
                res = (res << 1) + 1;
            } else {
                res = res << 1;
            }
            n = n >> 1;
        }
        return res;
    }
};

/*
    The key idea of the optimization is to look up a 4 bit chuck and find out what the reverse is. For example, reverse of 0001 is 1000 (in decimal reverse of 1 is 8). Another example, reverse of 1010 is 0101, meaning reverse of 10 is 5.

Based on this idea we could create a look up table:

value -> reverse

0 ------> 0

1 ------> 8

... ------> ...

15 ------> 15

This can be further optimized by using bytes lookup table of size 256 but I am too lazy to generate the table : ). Note, place the table initialization outside the reverseBits() routine is necessary for performance.

In theory, using look up table may improve the performance as we are dealing with 4 bits each time. Comparing to the method that iteratively swaps two bits each time, the method below should be faster.
Given the 600 test cases, the performance difference is not dramatic though.

During each iteration, shift the output 4 bits to the left, and discard the lowest 4 bits from the input. Make sure the reverse of current lowest 4 bits is saved to the current highest 4 bits in the output.

 */

/*
 * char tb[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

uint32_t reverseBits(uint32_t n) {
        int curr = 0;
        uint32_t ret = 0;
        uint32_t msk = 0xF;
        for(int i = 0; i< 8; i++) {
            ret = ret << 4;
            curr = msk&n;
            ret |= tb[curr];
            n = n >> 4;
        }
        return ret;
}
 */
