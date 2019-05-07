/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
 */

// 除了3和7意外，所有加1就变成4的倍数的奇数，适合加1运算
// 7来说，加1和减1的结果相同，我们可以不用管，对于3来说，减1的步骤小

class Solution {
public:
    int integerReplacement(int n) {

    }
};


class Solution {
public:
    int integerReplacement(int n) {
        long long t = n;
        int cnt = 0;
        while (t > 1) {
            ++cnt;
            if (t & 1) {
                if ((t & 2) && (t != 3)) ++t;
                else --t;
            } else {
                t >>= 1;
            }
        }
        return cnt;
    }
};

// recursive
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return 1 + integerReplacement(n / 2);
        else {
            long long t = n;
            return 2 + min(integerReplacement((t + 1) / 2), integerReplacement((t - 1) / 2));
        }
    }
}; 
