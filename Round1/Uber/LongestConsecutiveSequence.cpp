/*
Given an unsorted array of integers, find the length
of the longest consecutive elements sequence.

For example,
[100, 4, 200, 1, 3, 2]-> [1, 2, 3, 4]
return 4

Should be in O(n) time complexity
*/
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int LongestConsecutiveSequence(vector<int> &nums) {
    if (nums.empty()) return 0;
    unordered_set<int> nums_set(nums.begin(), nums.end());
    
    int res = 0, currLength = 0;
    while (!nums_set.empty()) {
        int left = *nums_set.begin(), right = *nums_set.begin() + 1;
        while (nums_set.count(left)) {
            nums_set.erase(left);
            --left;
        }
        
        while (nums_set.count(right)) {
            nums_set.erase(right);
            ++right;
        }
        
        currLength = right - left - 1;
        res = max(res, currLength);
    }
    return res;
}
           
int main() {
    vector<int> nums {100, 4, 200, 1, 3, 2};
    std::cout << LongestConsecutiveSequence(nums) << std::endl;
}

