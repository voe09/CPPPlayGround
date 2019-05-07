/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

// wrong [2, 7, 13, 14] 再第六个数时同时用到了2，7.两个都得+1
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);
        int k = primes.size();
        vector<int> powers(k, 0);
        while (res.size() < n) {
            vector<int> tmp(k, 0);
            int min_idx = 0;
            int min = INT_MAX;
            for (int i = 0; i < k; ++i) {
                tmp[i] = res[powers[i]] * primes[i];
                if (tmp[i] < min) {
                    min_idx = i;
                    min = tmp[i];
                }
            }
            powers[min_idx] += 1;
            res.push_back(min);
        }
        return res.back();
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);
        int k = primes.size();
        vector<int> powers(k, 0);
        while (res.size() < n) {
            vector<int> tmp(k, 0);
            int min = INT_MAX;
            for (int i = 0; i < k; ++i) {
                tmp[i] = res[powers[i]] * primes[i];
                if (tmp[i] < min) min = tmp[i];
            }
            for (int i = 0; i < k; ++i) {
                if (tmp[i] == min) powers[i] += 1;
            }
            res.push_back(min);
        }
        return res.back();
    }
};
