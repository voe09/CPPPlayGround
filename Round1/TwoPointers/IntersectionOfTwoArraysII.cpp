/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such
that you cannot load all elements into the memory at once?
 */

// https://github.com/kamyu104/LeetCode/blob/master/C++/intersection-of-two-arrays-ii.cpp

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int iter1 = 0, iter2 = 0;
        while (iter1 < nums1.size() && iter2 < nums2.size()) {
            if (nums1[iter1] < nums2[iter2]) ++iter1;
            else if (nums1[iter1] > nums2[iter2]) ++iter2;
            else {
                res.push_back(nums1[iter1]);
                ++iter1;
                ++iter2;
            }
        }
        return res;
    }
};
