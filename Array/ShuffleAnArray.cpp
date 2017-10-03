/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
public:
    Solution(vector<int> nums): vec(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }


    /* Fisher-Yates shuffle algorithm
	-- To shuffle an array a of n elements (indices 0..n-1):
	for i from 0 to n−2 do
     	j ← random integer such that i ≤ j < n
     	exchange a[i] and a[j]
    */    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = vec;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i); // 不能用rand() % res.size()，因为不是随机分布
            swap(res[i], res[t]);
        }
        return res;
    }
    
private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
