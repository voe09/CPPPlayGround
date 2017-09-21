/*
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
 */

/*
Below are steps to find the required number.
1) Find a lower limit on n digit numbers. For example, for n = 2, lower_limit is 10.
2) Find an upper limit on n digit numbers. For example, for n = 2, upper_limit is 99.
3) Consider all pairs of numbers where ever number lies in range [lower_limit, upper_limit]
 */

// TLE
class Solution {
public:
    int largestPalindrome(int n) {
        int lower_bound = 1, upper_bound = 9;
        while (n > 1) {
            lower_bound *= 10;
            upper_bound = upper_bound * 10 + 9;
            --n;
        }
        
        long long mx = INT_MIN;
        for (int i = upper_bound; i >= lower_bound; --i) {
            for (int j = i; j >= lower_bound; --j) {
                long long tmp = i * j;
                if (isPalindrome(tmp)) {
                    mx = max(mx, tmp);
                };
            }
        }
        return mx % 1337;
    }

private:
    bool isPalindrome(long long num) {
        int div = 1;
        while (num / div >= 10) {
            div *= 10;
        }

        while (num > 0) {
            int front = num / div;
            int back = num % 10;
            if (front != back) return false;
            num = (num % div) / 10;
            div /= 100;
        }

        return true;
    }
};

class Solution {
public:
    int largestPalindrome(int n) {
        long lower_bound = 1, upper_bound = 9;
        while (n > 1) {
            lower_bound *= 10;
            upper_bound = upper_bound * 10 + 9;
            --n;
        }

        long long upper = upper_bound * upper_bound, lower = lower_bound * lower_bound;
        for (long long i = upper; i >= lower; --i) {
            if (isPalindrome(i)) {
                for (long j = upper_bound; j >= lower_bound; --j) {
                    if (i % j == 0 && i / j <= upper_bound) return i % 1337;
                }
            }
        }
        return -1;
    }

private:
    bool isPalindrome(long long num) {
        int div = 1;
        while (num / div >= 10) {
            div *= 10;
        }

        while (num > 0) {
            int front = num / div;
            int back = num % 10;
            if (front != back) return false;
            num = (num % div) / 10;
            div /= 100;
        }

        return true;
    }
};
