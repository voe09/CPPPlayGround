/*
Given two arrays, write a function to compute their intersection.

 Notice

Each element in the result should appear as many times as it shows in 
both arrays.
The result can be in any order.
Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Challenge 
What if the given array is already sorted? How would you optimize your 
algorithm?
What if nums1's size is small compared to num2's size? Which algorithm 
is better?
What if elements of nums2 are stored on disk, and the memory is limited 
such that you cannot load all elements into the memory at once?
 */

class Solution {
public:

    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> res;
        while (p1 < m && p2 < n) {
            if (nums1[p1] == nums2[p2]) {
                res.push_back(nums1[p1]);
                ++p1, ++p2;
            } else if (nums1[p1] < nums2[p2]) {
                ++p1;
            } else {
                ++p2;
            }
        }
        return res;
    }
};
