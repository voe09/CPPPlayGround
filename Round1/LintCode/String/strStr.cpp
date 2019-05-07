/*
For a given source string and a target string, you should output the first 
index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Have you met this question in a real interview? Yes
Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer
may just want to test your basic implementation ability. But make sure your
confirm with the interviewer first.
Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.
 */

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source == NULL || target == NULL) return -1;
        string src(source), tgt(target);
        int n = src.size(), m = tgt.size();
        for (int i = 0; i < n  - m + 1; ++i) {
            if (src.substr(i, m) == tgt) return i;
        }
        return -1;
    }
};
