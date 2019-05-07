/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnop
qrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefgh
ijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty
substrings of p are present in s. In particular, your input is the string p 
and you need to output the number of different non-empty substrings of p in 
the string s.

Note: p consists of only lowercase English letters and the size of p might 
be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of 
string "zab" in the string s.
 */

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        unordered_set<string> lookup;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    dp[i][j] = true;
                    string tmp = p.substr(i, j - i + 1);
                    if (!lookup.count(tmp)) {
                        ++res;
                        lookup.insert(tmp);
                    }
                } else {
                    int diff = p[j] - p[i];
                    while (diff < 0)
                        diff += 26;
                    if (diff == j - i && dp[i][j - 1]) {
                        dp[i][j] = true;
                        string tmp = p.substr(i, j - i + 1);
                        if (!lookup.count(tmp)) {
                            lookup.insert(tmp);
                            ++res;
                        }
                    }
                }
            }
        }
        return res;
    }
};


/*
p的子字符串要么是单一的字符，要么是按字母顺序的子字符串。这道题遍历p的所有子字符
串会TLE，因为如果p很大的话，子字符串很多，会有大量的满足题意的重复子字符串，
必须要用到trick，而所谓技巧就是一般来说你想不到的方法。我们看abcd这个字符串，
以d结尾的子字符串有abcd, bcd, cd, d，那么我们可以发现bcd或者cd这些以d结尾的字符串
的子字符串都包含在abcd中，那么我们知道以某个字符结束的最大字符串包含其他以该字符
结束的字符串的所有子字符串，说起来很拗口，但是理解了我上面举的例子就行。那么题目
就可以转换为分别求出以每个字符(a-z)为结束字符的最长连续字符串就行了，
我们用一个数组cnt记录下来，最后在求出数组cnt的所有数字之和就是我们要的结果啦，
参见代码如下
 */

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);
        int result = 0, len = 0;
        for (int i = 0; i < p.length(); ++i) {
            int curr = p[i] - 'a';
            if (i > 0 && p[i - 1] != (curr + 26 - 1) % 26 + 'a') {
                len = 0;
            }
            if (++len > letters[curr]) {
                result += len - letters[curr];
                letters[curr] = len;
            }
        }
        return result;
    }
};

/*
这道题是说给了一个字符串P，需要从其中找到所有出现在S中的子串。 
这里的S的子串是一个比较神奇的存在，起就是abcdedf..zabcde…这样无限迭代下去的一个串
也就是只要P的字符串一直递增就好（z->a进位）

所以解题方法也很直接： 
找出以’a-z’每个字符结尾的情况下，最长的子串有多长，然后将其相加就可以
 */


