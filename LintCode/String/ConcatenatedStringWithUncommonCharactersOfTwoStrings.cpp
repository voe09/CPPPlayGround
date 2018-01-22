/*
Two strings are given and you have to modify 1st string such that
all the common characters of the 2nd strings have to be removed
and the uncommon characters of the 2nd string have to be concatenated
with uncommon characters of the 1st string.

Have you met this question in a real interview? Yes
Example
Given s1 = aacdb, s2 = gafd
return cbgf

Given s1 = abcs, s2 = cxzca;
return bsxz
 */

class Solution {
public:
    /*
     * @param : the 1st string
     * @param : the 2nd string
     * @return: uncommon characters of given strings
     */
    string concatenetedString(string &s1, string &s2) {
        // write your code here
        vector<bool> string_set1 (26, false);
        vector<bool> string_set2 (26, false);
        for (const auto &c : s2) {
            string_set2[c - 'a'] = true;
        }

        string res;
        for (const auto &c : s1) {
            if (!string_set2[c - 'a']) res.push_back(c);
            else string_set1[c - 'a'] = true;
        }

        for (const auto &c : s2) {
            if (!string_set1[c - 'a']) res.push_back(c);
        }
        return res;
    }
};
