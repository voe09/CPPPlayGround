class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (count(nums, mid) > maxOperations) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int count(vector<int> &nums, int mx) {
        int res = 0;
        for (int num : nums) {
            if (num > mx) {
                res += num % mx == 0 ? num / mx - 1 : num / mx;
            }
        }
        return res;
    }
};