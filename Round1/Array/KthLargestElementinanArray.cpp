/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

// use priority_queuei 其实是考Heap Sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
  	for (auto &num: nums) {
	    heap.push(num);
	    if (heap.size() > nums.size() - k + 1) heap.pop();
	}
	return heap.top();
    }
};

// QuickSelect Algorithm 考QuickSort
/*
跟快速排序一个思路。先取一个枢纽值，将数组中小于枢纽值的放在左边，大于枢纽值的放在右边，具体方法是用左右两个指针，如果他们小于枢纽值则将他们换到对面，一轮过后记得将枢纽值赋回分界点。如果这个分界点是k，说明分界点的数就是第k个数。否则，如果分界点大于k，则在左半边做同样的搜索。如果分界点小于k，则在右半边做同样的搜索。

注意
helper函数的k是k-1，因为我们下标从0开始的，我们要比较k和下标，来确定是否左半部分有k个数字。
互换左右时，也要先判断left <= right
*/

class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};
