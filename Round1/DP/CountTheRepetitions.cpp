/*
Define S = [s,n] as the string S which consists of n connected strings s. 
For example, ["abc", 3] ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2 if 
we can remove some characters from s2 such that it becomes s1. For example, 
“abc” can be obtained from “abdbec” based on our definition, but it can not be 
obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters 
long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings 
S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such 
that [S2,M] can be obtained from S1.

Example:

Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2
 */

/*
如果s2在S1中出现了N次，那么S2肯定在S1中出现了N/n2次，注意这里的大写表示字符串加上重复次数组成的大字符串。

所以我们得出结论，我们只要算出s2出现的次数，然后除以n2，就可以得出S2出现的次数了。

那么问题就是我们表示重复，我们遍历s1字符串n1次，表示每个s1字符串为一段，对于每段，我们有：

1. 出现在该段的s2字符串的累计出现次数

2. 一个nextIndex，其中s2[nextIndex]表示在下一段s1中你所要寻找的第一个字符。(比如说s1="abc", s2="bac", 由于要寻找s2的第一个字符b，而b在s1中的位置是1，所以nextIndex=1；同理，比如s1="abca", s2="bac"，那么nextIndex=2)

表示重复关键就在于nextIndex，比如对于下面这个例子：
 */

/*
https://discuss.leetcode.com/topic/72105/c-solution-inspired-by-70664914-with-organized-explanation
https://discuss.leetcode.com/topic/70887/very-clean-and-short-7ms-java-solution-based-on-70664914-s-idea
 */

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        
    }
};
