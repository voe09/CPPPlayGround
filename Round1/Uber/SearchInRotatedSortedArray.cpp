/*
Search in Rotated Sorted Array
 */

int BinarySearch(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) { // left is sorted
            if (nums[mid] > target && nums[left] <= target) right = mid - 1;
            else left = mid + 1;
        }
        else { // right is sorted
            if (nums[mid] < target && nums[right] >= target) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}
