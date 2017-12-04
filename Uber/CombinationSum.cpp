/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void helper(vector<int> &nums, int start, int target, vector<int> comb, vector<vector<int>> &res) {
    if (target == 0)  {
        res.push_back(comb);
        return;
    } else if (target < 0) return;

    for (int i = start; i < nums.size(); ++i) {
        comb.push_back(nums[i]);
        helper(nums, i, target - nums[i], comb, res);
        comb.pop_back();
    }
}

vector<vector<int>> combSum(vector<int> nums, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    sort(nums.begin(), nums.end());
    helper(nums, 0, target, comb, res);
    return res;
}

int main() {
    auto res = combSum({2, 3, 6, 7}, 7);
    for (const auto &vec : res) {
        for (const auto &num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void helper(vector<int> &nums, int start, int target, vector<int> comb, vector<vector<int>> &res) {
    if (target == 0)  {
        res.push_back(comb);
        return;
    } else if (target < 0) return;

    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        comb.push_back(nums[i]);
        helper(nums, i + 1, target - nums[i], comb, res);
        comb.pop_back();
    }
}

vector<vector<int>> combSum(vector<int> nums, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    sort(nums.begin(), nums.end());
    helper(nums, 0, target, comb, res);
    return res;
}

int main() {
    auto res = combSum({2, 3, 6, 7}, 7);
    for (const auto &vec : res) {
        for (const auto &num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

