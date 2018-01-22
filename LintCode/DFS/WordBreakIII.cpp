/*
Give a dictionary of words and a sentence with all whitespace removed, return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Have you met this question in a real interview? Yes
Example
Given a String CatMat
Given a dictionary ["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
return 3

we can form 3 sentences, as follows:
CatMat = Cat Mat
CatMat = Ca tM at
CatMat = C at Mat
 */

class Solution {
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string& s, unordered_set<string>& dict) {
        // Write your code here
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dict.count(s.substr(j, i - j))) {
                    dp[i] += dp[j];
                }
            }
        }
        return dp[n];
    }
};
