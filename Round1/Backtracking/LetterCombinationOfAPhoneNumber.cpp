/*
Given a digit string, return all possible letter combinations that the number 
could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> buttons{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.empty()) return res;
        DFS(buttons, digits, "", res);
        return res;
    }

private:
    void DFS(vector<string>& buttons, string digits, string cur, vector<string>& res) {
        if (digits.empty()) {
            res.push_back(cur);
            return;
        }

        int digit = digits[0] - '1';
        for (const auto& c : buttons[digit]) {
            DFS(buttons, digits.substr(1), cur + c, res);
        }
    }
};
