/*
Compare two strings A and B, determine whether A contains all of the 
characters in B.

The characters in string A and B are all Upper Case letters.

Example
For A = "ABCD", B = "ACD", return true.

For A = "ABCD", B = "AABC", return false.
*/

class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B) {
        // write your code here
        unordered_map<char, int> lookup;
        for (const auto& c : B) {
            ++lookup[c];
        }
        for (const auto& c : A) {
            if (lookup.count(c)) {
                --lookup[c];
                if (lookup[c] == 0)
                    lookup.erase(c);
            }
        }
        return (lookup.empty());
    }
};
