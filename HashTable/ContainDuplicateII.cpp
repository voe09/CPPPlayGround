/*
Given an array of integers and an integer k, find out whether there are 
two distinct indices i and j in the array such that nums[i] = nums[j] and the 
absolute difference between i and j is at most k.
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) return false;
        set<int> set;
        int length = nums.size();
        for (int i = 0; i < min(length, k + 1); ++i) {
            if (set.count(nums[i])) return true;
            set.insert(nums[i]);
        }

        for (int i = 0; i < length - k - 1; ++i) {
            set.erase(nums[i]);
            if (set.count(nums[i + k + 1])) return true;
            set.insert(nums[i + k + 1]);
        }
        return false;
    }
};
