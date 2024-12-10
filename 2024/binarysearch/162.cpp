class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            int curr = nums[mid], next = mid == nums.size() - 1 ? INT_MIN : nums[mid+1];
            if (curr < next) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};