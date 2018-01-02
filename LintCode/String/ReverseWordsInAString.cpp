/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Have you met this question in a real interview? Yes
Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 */

class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        // write your code here
        vector<string> words;
        istringstream is(s);
        string word;
        while (is >> word) {
            words.push_back(word);
        }
        string res;
        while (!words.empty()) {
            res += words.back() + " ";
            words.pop_back();
        }
        if (!res.empty())
            res.pop_back();
        return res;
    }
};
