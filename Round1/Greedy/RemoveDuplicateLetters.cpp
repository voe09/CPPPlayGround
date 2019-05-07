/*
Given a string which contains only lowercase letters, remove duplicate letters
so that every letter appear once and only once. You must make sure your result
is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
 */

/*
用栈。
首先对字符串出现的个数进行统计。
然后对字符串扫描，每遇到一个字符串，判断其是否在栈中，
如果在则跳过。（计数 – 1）
如果不在栈中，和栈顶的元素判断，要是当前栈顶的元素比较大而且cnt不为0
（也就是说之后还有这个元素），就把栈顶弹出。然后把当前的元素入栈。
 */





/*
The basic idea is to find out the smallest result letter by letter (one letter 
at a time). Here is the thinking process for input "cbacdcbc":

1. find out the last appeared position for each letter;
c - 7
b - 6
a - 2
d - 4
2. find out the smallest index from the map in step 1 (a - 2);
3. the first letter in the final result must be the smallest letter from index 
    0 to index 2;
4. repeat step 2 to 3 to find out remaining letters.
*the smallest letter from index 0 to index 2: a
*the smallest letter from index 3 to index 4: c
*the smallest letter from index 4 to index 4: d
*the smallest letter from index 5 to index 6: b
so the result is "acdb"

Notes:

*after one letter is determined in step 3, it need to be removed from the 
    "last appeared position map", and the same letter should be ignored in the following steps
*in step 3, the beginning index of the search range should be the index of 
    previous determined letter plus one
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> loc;
        for (int i = 0; i < s.size(); ++i) {
            loc[s[i]] = i;
        } 

        string res;
        int start = 0, end = INT_MAX;
        while (!loc.empty()) {
            for (auto it = loc.begin(); it != loc.end(); ++it) {
                end = min(end, it->second);
            }
            char tmp = 'z';
            int tmpLoc = start;
            for (int i = start; i <= end; ++i) {
                if (s[i] < tmp && loc.count(s[i])) {
                    tmp = s[i];
                    tmpLoc = i;
                }
            }

            loc.erase(tmp);
            start = tmpLoc + 1;
            end = INT_MAX;
            res += tmp;
        }

        return res;
    }
};
