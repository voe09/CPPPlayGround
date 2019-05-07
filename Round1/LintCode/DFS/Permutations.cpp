/*
Given a list of numbers, return all possible permutations.

 Notice

You can assume that there is no duplicate numbers in the list.

Have you met this question in a real interview? Yes
Example
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Challenge 
Do it without recursion.
 */

/*
参考 Wikipedia 上的字典序算法，大致步骤如下：
从后往前寻找索引满足 a[k] < a[k + 1], 如果此条件不满足，则说明已遍历到最后一个。
从后往前遍历，找到第一个比a[k]大的数a[l], 即a[k] < a[l].
交换a[k]与a[l].
反转k + 1 ~ n之间的元素。
 */

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.empty() || nums.size() <= 1) {
            res.push_back(nums);
            return res;
        }

        sort(nums.begin(), nums.end());
        while (true) {
            res.push_back(nums);
            
            // Step1 find nums[i] < nums[i + 1]
            int i = 0;
            for (i = nums.size() - 2; i >= 0; --i) {
                if (nums[i] < nums[i + 1]) {
                    break;
                } else if (i == 0) {
                    return res;
                }
            }

            // step2: find nums[i] < nums[j]
            int j = 0;
            for (j = nums.size() - 1; j > i; --j) {
                if (nums[i] < nums[j]) break;
            }

            // step3: swap between nums[i] and nums[j]
            swap(nums[i], nums[j]);

            // step4: reverse between [i + 1, n - 1]
            reverse(nums, i + 1, nums.size() - 1);
        }
        return res;
    }

private:
    void reverse(vector<int> &nums, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
};
