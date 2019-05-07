/*
Given an array of integers, find out whether there are two distinct indices i 
and j in the array such that the absolute difference between nums[i] and nums[j]
is at most t and the absolute difference between i and j is at most k.
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound(static_cast<long>(nums[i]) - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
