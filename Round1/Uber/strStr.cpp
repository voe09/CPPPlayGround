/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

int strStr(string &needle, string &haystack) {
    int res = -1;
    int m = needle.size(), n = haystack.size();
    for (int i = 0; i < n - m + 1; ++i) {
        if (haystack.substr(i, m) == needle) {
            res = i;
            break;
        }
    }
    return res;
}
