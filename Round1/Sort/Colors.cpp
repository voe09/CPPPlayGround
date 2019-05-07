/*
Given an array with n objects colored red, white or blue, sort them so that 
objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then 
overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
 */

/*
这里要求one pass完成排序，需要利用只有数组元素只有3个数的特性，否则无法完成。排序完成后一定是0...01...12....2，所以可以扫描数组，当遇到0时，交换到前部，当遇到1时，交换到后部。用双指针left, right来记录当前已经就位的0序列和2序列的边界位置。

假设已经完成到如下所示的状态：

0......0   1......1  x1 x2 .... xm   2.....2
              |           |               |
            left        cur          right

(1) A[cur] = 1：已经就位，cur++即可
(2) A[cur] = 0：交换A[cur]和A[left]。由于A[left]=1或left=cur，所以交换以后A[cur]已经就位，cur++，left++
(3) A[cur] = 2：交换A[cur]和A[right]，right--。由于xm的值未知，cur不能增加，继续判断xm。
cur > right扫描结束。
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        int curr = 0;
        while (curr <= blue) {
            if (nums[curr] == 0) std::swap(nums[curr++], nums[red++]);
            else if (nums[curr] == 2) std::swap(nums[curr], nums[blue--]);
            else ++curr;
        }
    }
};
