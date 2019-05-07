/*
Given a digit string excluded 01, return all possible letter combinations that
the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Cellphone

 Notice

Although the above answer is in lexicographical order, your answer could be in any order you want.

Have you met this question in a real interview? Yes
Example
Given "23"

Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
 */

class Solution {
public:
    /*
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<vector<char>> lookup {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'},
                  {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
                  {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> res;
        string curr;
        if (digits.empty()) return res;
        helper(digits, 0, lookup, curr, res);
        return res;
    }

private:
    void helper(string &digits, int idx, vector<vector<char>> &lookup,
            string &curr, vector<string> &res) {
        if (idx == digits.size()) {
            res.push_back(curr);
            return;
        }
        
        int digit = digits[idx] - '0';
        vector<char> &dict = lookup[digit];
        for (const auto &c : dict) {
            curr += c;
            helper(digits, idx + 1, lookup, curr, res);
            curr.pop_back();
        }
    }
};
