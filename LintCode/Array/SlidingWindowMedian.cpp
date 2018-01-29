/*
Given an array of n integer, and a moving window(size k), move the window 
at each iteration from the start of the array, find the median of the
element inside the window at each moving. (If there are even numbers in
the array, return the N/2-th number after sorting the element in the
window. )

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]

At first the window is at the start of the array like this

[ | 1,2,7 | ,8,5] , return the median 2;

then the window move one step forward.

[1, | 2,7,8 | ,5], return the median 7;

then the window move one step forward again.

[1,2, | 7,8,5 | ], return the median 7;

Challenge 
O(nlog(n)) time
 */

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        multiset<int> small, large;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k]))
                    small.erase(small.find(nums[i - k]));
                else if (large.count(nums[i - k])) 
                    large.erase(large.find(nums[i - k]));
            }

            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= *large.begin())
                    small.insert(nums[i]);
                else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            } else {
                if (nums[i] >= *small.rbegin()) 
                    large.insert(nums[i]);
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if (i >= (k - 1)) {
                res.push_back(*small.rbegin());
            }
        }
        return res;
    }
};
