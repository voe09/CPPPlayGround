/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be 
a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
 */

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        int sum = 0;
        vector<int> comb;
        DFS(k, 1, sum, n, comb, res);
        return res;
    }

private:
    void DFS(int& k, int start, int& sum, int n, vector<int>& comb,
            vector<vector<int>>& res) {
        if (k == 0) {
            if (sum == n)
                res.push_back(comb);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            comb.push_back(i);
            sum += i;
            --k;
            DFS(k, i + 1, sum, n, comb, res);
            ++k;
            sum -= i;
            comb.pop_back();
        }
    }
};
