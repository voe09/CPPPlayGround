/*
Implement int sqrt(int x).

Compute and return the square root of x.

Have you met this question in a real interview? Yes
Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3

Challenge 
O(log(x))
 */

class Solution {
public:
    /*
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long long left = 0, right = (x / 2) + 1;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
