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


#include <vector>
#include <iostream>
using namespace std;

//void helper(vector<int> &nums, int target,
//            vector<int> &curr, vector<vector<int>> &res) {
//    if (target <= 0) {
//        if (target == 0) res.push_back(curr);
//        return;
//    }
//
//    for (int i = 0; i < nums.size(); ++i) {
//        curr.push_back(nums[i]);
//        helper(nums, target - nums[i], curr, res);
//        curr.pop_back();
//    }
//}
//
//vector<vector<int>> CombinationSum(vector<int> nums, int target) {
//	if (nums.empty()) return {};
//	int sign = nums[0] > 0 ? 1 : -1;
//	if (sign == 1 && target <= 0) return {};
//	if (sign == -1 && target >= 0) return {};
//	if (sign == -1) {
//		for (auto &num : nums) num = abs(num);
//		target = abs(target);
//	}
//    vector<vector<int>> res;
//    vector<int> curr;
//    helper(nums, target, curr, res);
//    if (sign == -1) {
//    	for (auto &vec : res) {
//    		for (auto &num : vec)
//    			num = sign * num;
//		}
//	}
//    return res;
//}

int numOfSum(vector<int> nums, int target) {
	if (target <= 0) return 0;
	vector<int> dp (target + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= target; ++i) {
		for (const auto &num : nums) {
			if (num <= i)
				dp[i] += dp[i - num];
		}
	}
	return dp[target];
}

int main() {
	vector<int> nums {2, 3, 5, 7};
	int res = numOfSum(nums, 7);
	cout << res << endl;
//	vector<int> nums {-2, -3, -5, -7};
//	auto res1 = CombinationSum(nums, -7);
//	for (const auto &vec : res1) {
//		for (const auto &num : vec) {
//			cout << num << " ";
//		}
//		cout << endl;
//	}
//
//	vector<int> nums2 {2, 3, 5, 7};
//	auto res = CombinationSum(nums2, 9);
//	for (const auto &vec : res) {
//		for (const auto &num : vec) {
//			cout << num << " ";
//		}
//		cout << endl;
//	}

//	vector<int> num {};
//	auto res = CombinationSum(num, 9);
//	cout << res.empty() << endl;
}
