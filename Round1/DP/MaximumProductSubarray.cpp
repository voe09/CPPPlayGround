/*
Find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */

/*
Maximum Subarray那题的变种。由于正负得负，负负得正的关系。以A[i]结尾的max product subarray同时取决于以A[i-1]结尾的max / min product subarray以及A[i]本身。因此，对每个i，需要记录min/max product两个状态：

max_product[i] = max(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i]) 
min_product[i] = min(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i]) 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0], mn = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmax = mx, tmin = mn;
            mx = max(max(nums[i], tmax * nums[i]), tmin * nums[i]);
            mn = min(min(nums[i], tmax * nums[i]), tmin * nums[i]);
            res = max(res, mx);
        }
        return res;
    }
};
