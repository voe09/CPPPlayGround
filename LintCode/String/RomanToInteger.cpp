/*
Given a roman numeral, convert it to an integer.

The answer is guaranteed to be within the range from 1 to 3999.

Have you met this question in a real interview? Yes
Clarification
What is Roman Numeral?

https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
http://baike.baidu.com/view/42061.htm
Example
IV -> 4

XII -> 12

XXI -> 21

XCIX -> 99
 */

/*

基本字符
I
V
X
L
C
D
M
相应的阿拉伯数字表示为
1
5
10
50
100
500
1000
 
1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
4、正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
5、在一个数的上面画一条横线，表示这个数扩大1000倍。
 */

class Solution {
public:
    /*
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
        // write your code here
        int res = 0;
        unordered_map<char, int> m {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                    {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            int val = m[s[i]];
            if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]])
                res += val;
            else res -= val;
        }
        return res;
    }
};
