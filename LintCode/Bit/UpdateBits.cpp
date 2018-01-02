/*
Given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to set all bits between i and j in N equal to M (e g , 
M becomes a substring of N located at i and starting at j)

 Notice

In the function, the numbers N and M will given in decimal, you should
also return a decimal number.

Have you met this question in a real interview? Yes
Clarification
You can assume that the bits j through i have enough space to fit all of M.
That is, if M=10011， you can assume that there are at least 5 bits between
j and i. You would not, for example, have j=3 and i=2, because M could not
fully fit between bit 3 and bit 2.

Example
Given N=(10000000000)2, M=(10101)2, i=2, j=6

return N=(10001010100)2

Challenge 
Minimum number of operations?
 */

/*
得到第i位到第j位的比特位为0，而其他位均为1的掩码mask。
使用mask与 N 进行按位与，清零 N 的第i位到第j位。
对 M 右移i位，将 M 放到 N 中指定的位置。
返回 N | M 按位或的结果。
 */

class Solution {
public:
    /*
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int ones = ~0;
        int mask = 0;
        if (j < 31) {
            int left = ones << (j + 1);
            int right = 1 << i - 1;
            mask = left | right;
        } else {
            mask  = (1 << i) - 1;
        }
        return (n & mask) | (m << i);
    }
};


/*
C++

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int ones = ~0;
        int left = ones << (j + 1);
        int right = ((1 << i) - 1);
        int mask = left | right;

        return (n & mask) | (m << i);
    }
};
源码分析

在给定测试数据[-521,0,31,31]时出现了 WA, 也就意味着目前这段程序是存在 bug 的，
此时m = 0, i = 31, j = 31，仔细瞅瞅到底是哪几行代码有问题？本地调试后发现问题出
在left那一行，left移位后仍然为ones, 这是为什么呢？在j为31时j + 1为32，
也就是说此时对left位移的操作已经超出了此时int的最大位宽！

C++

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int ones = ~0;
        int mask = 0;
        if (j < 31) {
            int left = ones << (j + 1);
            int right = ((1 << i) - 1);
            mask = left | right;
        } else {
            mask = (1 << i) - 1;
        }

        return (n & mask) | (m << i);
    }
};
源码分析

使用~0获得全1比特位，在j == 31时做特殊处理，即不必求left。求掩码的右侧1时使用了(1 << i) - 1, 题中有保证第i位到第j位足以容纳 M, 故不必做溢出处理。

复杂度分析

时间复杂度和空间复杂度均为 O(1)O(1)O(1).

C++

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // get the bit width of input integer
        int bitwidth = 8 * sizeof(n);
        int ones = ~0;
        // use unsigned for logical shift
        unsigned int mask = ones << (bitwidth - (j - i + 1));
        mask = mask >> (bitwidth - 1 - j);

        return (n & (~mask)) | (m << i);
    }
};
源码分析

之前的实现需要使用if判断，但实际上还有更好的做法，即先获得mask的反码，最后取反即可。但这种方法需要提防有符号数，因为 C/C++ 中对有符号数的移位操作为算术移位，也就是说对负数右移时会在前面补零。解决办法可以使用无符号数定义mask.

按题意 int 的位数为32，但考虑到通用性，可以使用sizeof获得其真实位宽。

复杂度分析

时间复杂度和空间复杂度均为 O(1)O(1)O(1).
 */
