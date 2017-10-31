/*
Given two strings, you have to find the missing string.

Have you met this question in a real interview? Yes
Example
Given a string str1 = This is an example
Given another string str2 = is example

Return ["This", "an"]
 */

class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string str1, string str2) {
        // Write your code here
        stringstream sstr1(str1);
        stringstream sstr2(str2);
        unordered_map<string, int> lookup;
        string word;
        while (sstr2 >> word) {
            ++lookup[word];
        }

        vector<string> res;
        while (sstr1 >> word) {
            if (!lookup.count(word))
                res.push_back(word);
            else {
                --lookup[word];
                if (lookup[word] == 0) lookup.erase(word);
            }
        }
        return res;
    }
};
