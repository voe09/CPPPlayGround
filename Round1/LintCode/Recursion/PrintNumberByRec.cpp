/*
Print numbers from 1 to the largest number with N digits by recursion.

 Notice

It's pretty easy to do recursion like:

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
however this cost a lot of recursion memory as the recursion depth maybe
very large. Can you do it in another way to recursive with at most N depth?

Have you met this question in a real interview? Yes
Example
Given N = 1, return [1,2,3,4,5,6,7,8,9].

Given N = 2, return [1,2,3,4,5,6,7,8,9,10,11,12,...,99].

Challenge 
Do it in recursion, not for-loop.
 */

class Solution {
public:
    /*
     * @param n: An integer
     * @return: An array storing 1 to the largest number with n digits
     */
    void helper(int n, vector<int> &nums) {
        if (n < 1) return;
        helper(n - 1, nums);

        int base = static_cast<int>(pow(10.0, n - 1));
        int size = nums.size();
        for (int i = 1; i < 10; ++i) {
            nums.push_back(i * base);
            for (int j = 0; j < size; ++j) {
                nums.push_back(nums[j] + i * base);
            }
        }
    }

    vector<int> numbersByRecursion(int n) {
        // write your code here
        if (n == 0) return {};
        vector<int> res;
        helper(n, res);
        return res;
    }
};
