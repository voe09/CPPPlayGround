/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/

ass Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        for (int i = 1; i < n; ++i) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        
        for(int i = n - 2; i >= 0; --i) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        
        for (int i = 0; i < n; ++i) {
            res[i] = left[i] * right[i];
        }
        
        return res;
    }
};

/*

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int right = 1;
        for (int i = n - 2; i >= 0; --i) {
            right *= nums[i + 1];
            res[i] *= right;
        }
        
        return res;
    }
};
