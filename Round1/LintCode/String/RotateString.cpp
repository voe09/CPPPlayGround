/*
Given a string and an offset, rotate string by offset. 
(rotate from left to right)

Have you met this question in a real interview? Yes
Example
Given "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
Challenge 
Rotate in-place with O(1) extra memory.
 */

class Solution {
public:
    /*
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if (str.empty()) return;
        int n = str.size();
        offset %= n;
        reverse(str, 0, n - offset - 1);
        reverse(str, n - offset, n - 1);
        reverse(str, 0, n - 1);
    }

private:
    void reverse(string &str, int left, int right) {
        while (left <= right) {
            swap(str[left++], str[right--]);
        }
    }
};
