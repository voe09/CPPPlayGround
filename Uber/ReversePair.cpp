/*
给一个 list，返回 reversion pairs. Reversion pair （a, b） 的要求是在 
original list 中 a 在 b 的前面，但a 的值 比 b 的>    值要大。
*/

/*
给一个 list，返回 reversion pairs. Reversion pair （a, b） 的要求是在 original list 中 a 在 b 的前面，
但a 的值 比 b 的>值要大。
*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> merge_and_count(vector<int> &nums, int start, int end, long long &res) {
    if (start == end) return {nums[start]};
    int mid = start + (end - start) / 2;
    vector<int> left = merge_and_count(nums, start, mid, res);
    vector<int> right = merge_and_count(nums, mid + 1, end, res);

    // count
    int idx = 0;
    for (int i = 0; i < left.size(); ++i) {
        for (; idx < right.size(); ++idx) {
            if (right[idx] >= left[i]) break;
        }
        res += idx;
    }

    // merge
    vector<int> tmp (end - start + 1, 0);
    int l = 0, r = 0;
    int curr = 0;
    while (l < left.size() && r < right.size()) {
        tmp[curr++] = (left[l] < right[r]) ? left[l++] : right[r++];
    }

    while (l < left.size()) {
        tmp[curr++] = left[l++];
    }

    while (r < right.size()) {
        tmp[curr++] = right[r++];
    }

    return tmp;
}

long long ReversePairs(vector<int> &nums) {
    if (nums.empty()) return 0;
    long long res = 0;
    merge_and_count(nums, 0, nums.size() - 1, res);
    return res;
}

int main() {
    vector<int> nums {2, 4, 1, 3, 5};
    std::cout << ReversePairs(nums) << std::endl;
}

