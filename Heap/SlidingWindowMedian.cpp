/*
Median is the middle value in an ordered integer list. If the size of the list 
is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers
in the window. Each time the sliding window moves right by one position. Your
job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note: 
You may assume k is always valid, ie: k is always smaller than input array's
size for non-empty array.
 */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        multiset<int> small, large;
        vector<double> res;
        for (int i = 0; i < nums.size(); ++i) {
            addNumber(small, large, nums[i]);
            if (i < k - 1) {
                continue;
            } else if (i == k - 1) {
                retrieveMedian(small, large, res);
            } else {
                removeNumber(small, large, nums[i - k]);
                retrieveMedian(small, large, res);
            }
        }
        return res;
    }

private:
    void addNumber(multiset<int>& small, multiset<int>& large, int target) {
        small.insert(target);
        balanceHeap(small, large);
    }

    void removeNumber(multiset<int>& small, multiset<int>& large, int target) {
        auto it = small.find(target);
        if (it != small.end()) {
            small.erase(it);
        } else {
            auto it = large.find(target);
            large.erase(it);
        }
        balanceHeap(small, large);
    }

    void retrieveMedian(multiset<int>& small, multiset<int>& large, vector<double>& res) {
        if (small.size() > large.size()) res.push_back(*small.rbegin());
        else {
            double l = *small.rbegin();
            double r = *large.begin();
            res.push_back((l + r) / 2);
        }
    }

    void balanceHeap(multiset<int>& small, multiset<int>& large) {
        if (small.size() > large.size() + 1) {
            int tmp = *(std::prev(small.end()));
            small.erase(std::prev(small.end()));
            large.insert(tmp);
        } else if (small.size() < large.size()) {
            int tmp = *large.begin();
            large.erase(large.begin());
            small.insert(tmp);
        } else if {
            if (large.empty()) return;
            int l = *(std::prev(small.end()));
            int r = *(large.begin());
            if (l > r) {
                small.erase(std::prev(small.end()));
                small.insert(r);
                large.erase(large.begin());
                large.insert(l);
            }
        }
    }
};
