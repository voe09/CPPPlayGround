/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given
prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]
is the sequence of the first 12 super ugly numbers given 
primes = [2, 7, 13, 19] of size 4.

 Notice

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000
Have you met this question in a real interview? Yes
Example
Given n = 6, primes = [2, 7, 13, 19] return 13
 */

class Solution {
public:
    /*
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // write your code here
        int length = primes.size();
        vector<int> idx (length, 0);
        vector<int> res (1, 1);
        while (n > 1) {
            int min_val = INT_MAX;
            vector<int> min_idx;
            for (int i = 0; i < length; ++i) {
                if (min_val > primes[i] * res[idx[i]]) {
                    min_val = primes[i] * res[idx[i]];
                    min_idx.clear();
                    min_idx.push_back(i);
                }
                else if (min_val == primes[i] * res[idx[i]]) {
                    min_idx.push_back(i);
                }
            }
            for (int i : min_idx) {
                ++idx[i];
            }
            res.push_back(min_val);
            --n;
        }
        return res.back();
    }
};
