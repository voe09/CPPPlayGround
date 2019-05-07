/*
Write a function, give a string A consisting of N characters and a string B
consisting of M characters, returns the number of times A must be stated 
such that B is a substring of the repeated string. If B can never be a 
substring of the repeated A, then your function should return -1.

Assume that 0 <= N <= 1000, 1 <= M <= 1000

Example
Given A = abcd, B = cdabcdab

your function should return 3, bcause after stating string A three times 
we obtain the string abcdabcdabcd. String B is a substring of this string.
 */

/*
没有用到字符串自带的find函数，而是逐个字符进行比较，循环字符串A中的
所有字符，然后用个变量j，初始化为0，用来循环字符串B中的字符，每个字符
和A中对应的字符进行比较，此时从A中取字符就要把A当作一个循环数组来处理，
用(i+j)%m来取字符，还要确保j小于n，避免越界，如果字符匹配的话，j自增1。
while 循环结束后，如果j等于n了，说明B中所有的字符都成功匹配了，那么我们
来计算A的重复次数，通过(i+j-1)/m + 1来得到，注意i+j要减1再除以m，之后再
加上一次。因为当i+j正好等于m时，说明此时不用重复A，那么(i+j-1)/m + 1还是
等于1，当i+j>m的时候，需要重复A了，(i+j-1)/m + 1也可以得到正确的结构
 */

class Solution {
public:
    /*
     * @param : string A to be repeated
     * @param : string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        // write your code here
       int m = A.size(), n = B.size();
       for (int i = 0; i < m; ++i) {
            int j = 0;
            while (j < n && A[(i + j) % m] == B[j]) ++j;
            if (j == n) return (i + j - 1) / m + 1;
       }
       return -1;
    }
};
