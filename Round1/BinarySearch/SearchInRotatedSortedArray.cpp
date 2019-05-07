/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */

/*
idea:  1) Find out pivot point and divide the array in two
      sub-arrays.
       2) Now call binary search for one of the two sub-arrays.
          (a) If element is greater than 0th element then
             search in left array
           (b) Else Search in right array
       3) If element is found in selected sub-array then return index
       Else return -1.
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        // Find the pivot, wrong answer, use binary search to find pivot
        int length = nums.size(), pivot = 1;
        for (;pivot < length; ++pivot) {
            if (nums[pivot] < nums[pivot - 1])
                break;
        }
        if (pivot == length) return BinarySearch(nums, 0, length - 1, target);
        if (nums[0] > target) return BinarySearch(nums, pivot, length - 1, target);
        else if (nums[0] < target) return BinarySearch(nums, 0, pivot - 1, target);
        else return 0;
    }

private:
    int BinarySearch(vector<int>& nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) start = mid + 1;
            else if (nums[mid] > target) end = mid - 1;
            else return mid;
        }
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;
        return -1;
    }
};

/* One pass
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[r], recur for arr[mid+1..r].
    b) Else recur for arr[l..mid] 
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[mid] >= nums[left] && nums[left] <= target && target < nums[mid]) ||
                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};


/*
当target != A[mid]时，可以分情况判断：
当A[mid] < A[end] < A[start]：情况1，右半序列A[mid+1 : end] sorted
A[mid] < target <= A[end], 右半序列，否则为左半序列。
当A[mid] > A[start] > A[end]：情况2，左半序列A[start : mid-1] sorted
A[start] <= target < A[mid], 左半序列，否则为右半序列
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int low = 0, high = nums.size() - 1;
        return search(nums, low, high, target);
    }

    int search(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else {
            if (nums[mid] < nums[end]) { // right half sorted
                if (target > nums[mid] && target <= nums[end])
                    return search(nums, mid + 1, end, target);
                else
                    return search(nums, start, mid - 1, target);
            } else {
                if (target >= nums[start] && target < nums[mid])
                    return search(nums, start, mid - 1, target);
                else
                    return search(nums, mid + 1, end, target);
            }
        }
    }
};

// Iterative method
class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0, end = n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(A[mid]==target) return mid;  
            
            if(A[mid]<A[end]) { // right half sorted
                if(target>A[mid] && target<=A[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
            else {  // left half sorted
                if(target>=A[start] && target<A[mid]) 
                    end = mid-1;
                else
                    start = mid+1;
            }
        }
        return -1;
    }
};


