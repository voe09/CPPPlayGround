/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

// Wrong solution
// 12
// [1, 10, 1, 1, 7, 5]
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum < s) return 0;
	int start = 0;
	int end = nums.size() - 1;
	while (sum >= s) {
	    if (nums[start] > nums[end]){
		sum -= nums[end];
		end -= 1;
	    } else { 
		sum -= nums[start];
		start += 1;
	    }
	}
	return end - start + 2;    
    }
};

// Correct solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};
