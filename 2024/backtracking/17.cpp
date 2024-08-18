class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>> keys = {
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };

        vector<string> res;
        string word;
        helper(digits, 0, keys, word, res);

        return res;
    }

    void helper(string &digits, int i, vector<vector<char>> &keys, string &word, vector<string> &res) {
        if (i == digits.size()) {
            res.push_back(word);
            return;
        }

        vector<char> &chars = keys[digits[i] - '0'];
        for (char c : chars) {
            word.push_back(c);
            helper(digits, i+1, keys, word, res);
            word.pop_back();
        }
    }
};