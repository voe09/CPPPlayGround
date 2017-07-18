/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice 
in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
        for (const auto &num: nums) {
            if (set.count(num)) return true;
            set.insert(num);
        }
        return false;
    }
};
