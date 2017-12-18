
void helper(vector<int> &nums, int target,
            vector<int> curr, vector<vector<int>> &res) {
    if (target <= 0) {
        if (target == 0) res.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        curr.push_back(nums[i]);
        helper(nums, target, curr, res);
        curr.pop_back();
    }
}

vector<vector<int>> CombinationSum(vector<int> nums, int target) {
    vector<vector<int>> res;
    vector<int> curr;
    helper(nums, target, curr, res);
    return res;
}
