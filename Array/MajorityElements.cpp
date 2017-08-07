/*
Given an array of size n, find the majority element. The majority element is 
the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element 
always exist in the array.
*/

/*
Initialize an element m and a counter i with i = 0
For each element x of the input sequence:
    If i = 0, then assign m = x and i = 1
    else if m = x, then assign i = i + 1
    else assign i = i − 1
Return m
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash_table;
        for (auto &num: nums) {
            hash_table[num] += 1;
        }
        for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
            if ((it->second) > n / 2) {
                return it->first;
            }
        }
    }
};
