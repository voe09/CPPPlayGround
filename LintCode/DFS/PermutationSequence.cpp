/*
Given n and k, return the k-th permutation sequence.

 Notice

n will be between 1 and 9 inclusive.

Have you met this question in a real interview? Yes
Example
For n = 3, all permutations are listed as follows:

"123"
"132"
"213"
"231"
"312"
"321"
If k = 4, the fourth permutation is "231"

Challenge 
O(n*k) in time complexity is easy, can you do it in O(n^2) or less?
 */

class Solution {
public:
    /*
     * @param n: n
     * @param k: the k th permutation
     * @return: return the k-th permutation
     */
    string getPermutation(int n, int k) {
        // write your code here
        int total_perm = 1;
        for (int i = n; i >= 1; --i) {
            total_perm *= i;
        }
        string res = "";
        while (total_perm > 1) {
            findChar(total_perm, k, 
        }
    }
};
