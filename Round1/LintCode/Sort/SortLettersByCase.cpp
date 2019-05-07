/*
Given a string which contains only letters. Sort it by lower case first 
and upper case second.

 Notice

It's NOT necessary to keep the original order of lower-case letters and upper case letters.

Have you met this question in a real interview? Yes
Example
For "abAcD", a reasonable answer is "acbAD"

Challenge 
Do it in one-pass and in-place.
 */

class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        // write your code here
        int left = 0, right = chars.size() - 1;
        while (left < right) {
            while (left < right && isLower(chars[left])) ++left;
            while (left < right && !isLower(chars[right])) --right;
            if (left < right) {
                swap(chars[left++], chars[right--]);
            }
        }
    }

private:
    bool isLower(char &c) {
        return c >= 'a' && c <= 'z';
    }
};
