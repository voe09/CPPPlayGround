/*
Given two strings, write a method to decide if one is a permutation of the other.

Have you met this question in a real interview? Yes
Example
abcd is a permutation of bcad, but abbe is not a permutation of abe
*/

class Solution {
public:
    /*
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        // write your code here
        if (A.size() != B.size()) return false;
        vector<int> counts (26, 0);
        for (const auto &c : A) {
            int idx = c - 'a';
            ++counts[idx];
        }

        for (const auto &c : B) {
            int idx = c - 'a';
            --counts[idx];
        }

        for (int i = 0; i < 26; ++i) {
            if (counts[i] != 0) return false;
        }

        return true;
    }
};
