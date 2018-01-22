/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence 
ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes
a list of n numbers as input and checks whether there is a 132 pattern in the
list.

n will be less than 20,000.

Have you met this question in a real interview? Yes
Example
Given nums = [1, 2, 3, 4]
return False // There is no 132 pattern in the sequence.

Given nums = [3, 1, 4, 2]
return True // There is a 132 pattern in the sequence: [1, 4, 2].
 */

class Solution {
public:
    /*
     * @param nums: a list of n integers
     * @return: true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int> &nums) {
        // write your code here
        int third = INT_MIN;
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            while (!stk.empty() && nums[i] > stk.top()) {
                third = stk.top(); 
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            else while (!s.empty() && nums[i] > s.top()) {
                third = s.top(); s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
