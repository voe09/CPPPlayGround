/*
Given an integer array, find a subarray where the sum of numbers is zero. 
Your code should return the index of the first number and the index of the 
last number.

 Notice

There is at least one subarray that it's sum equals to zero.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        unordered_map<int, vector<int>> m;
        int prev = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            prev += nums[i];
            if (prev == 0) {
                res.push_back(0);
                res.push_back(i);
                break;
            }
            if (m.count(prev)) {
                res.push_back(m[prev][0] + 1);
                res.push_back(i);
                break;
            }
            m[prev].push_back(i);
        }

        return res;
    }
};
