/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> Product(vector<int> &nums) {
    if (nums.empty()) return {};
    int n = nums.size();
    vector<int> res (n, 1);
    for (int i = 1; i < n; ++i) {
        res[i] = nums[i - 1] * res[i - 1];
    }

    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        res[i] = right * res[i];
        right = right * nums[i];
    }

    return res;
}

int main() {
    vector<int> inputs {1, 2, 3, 4, 5};
    vector<int> res = Product(inputs);
    for (const auto &num : res) {
        std::cout << num << std::endl;
    }
}
