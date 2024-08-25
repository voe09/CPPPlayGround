class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        int sum = 0;

        helper(candidates, 0, curr, sum, target, res);
        return res;
    }

    void helper(vector<int>& candidates, int i, vector<int>& curr, int& sum, int target, vector<vector<int>>& res) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            curr.push_back(candidates[j]);
            sum += candidates[j];
            helper(candidates, j, curr, sum, target, res);
            sum -= candidates[j];
            curr.pop_back();
        }
    }
};