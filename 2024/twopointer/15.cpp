class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            vector<vector<int>> tups = helper(nums, i+1, -nums[i]);
            for (vector<int> &tup : tups) {
                res.push_back({nums[i], tup[0], tup[1]});
            }
        }
        return res;
    }

    vector<vector<int>> helper(vector<int> &nums, int start, int target) {
        vector<vector<int>> res;
        int l = start, r = nums.size() - 1;
        while (l < r) {
            while (l != start && l < r && nums[l] == nums[l-1]) l++;
            while (r != nums.size() - 1 && l < r && nums[r] == nums[r+1]) r--;
            if (l == r) break;
            if (nums[l] + nums[r] == target) {
                res.push_back({nums[l], nums[r]});
                l++, r--;
            } else if (nums[l] + nums[r] > target) r--;
            else l++;
        }
        return res;
    }
};