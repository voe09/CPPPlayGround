/*
Given an integer array nums, find the sum of the elements between indices i 
and j (i ≤ j), inclusive.

The update(i, val) function modifies nums 
by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and 
sumRange function is distributed evenly.
*/

// http://blog.csdn.net/liyuefeilong/article/details/50551831
// http://blog.csdn.net/int64ago/article/details/7429868
// 上面说的感觉不太好，Binary Index Tree or Segment Tree更好懂

class NumArray {
public:
    NumArray(vector<int> nums) {

    }

    void update(int i, int val) {

    }

    int sumRange(int i, int j) {

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */



/* Binary Index Tree Youtube video
Binary Indexed Tree is represented as an array. Let the array be BITree[]. 
Each node of Binary Indexed Tree stores sum of some elements of given array. 
Size of Binary Indexed Tree is equal to n where n is size of input array. 
In the below code, we have used size as n+1 for ease of implementation.

getSum(index): Returns sum of arr[0..index]
// Returns sum of arr[0..index] using BITree[0..n].  It assumes that
// BITree[] is constructed for given array arr[0..n-1]
1) Initialize sum as 0 and index as index+1.
2) Do following while index is greater than 0.
...a) Add BITree[index] to sum
...b) Go to parent of BITree[index].  Parent can be obtained by removing
     the last set bit from index, i.e., index = index - (index & (-index))
3) Return sum.

update(index, val): Updates BIT for operation arr[index] += val
// Note that arr[] is not changed here.  It changes
// only BI Tree for the already made change in arr[].
1) Initialize index as index+1.
2) Do following while index is smaller than or equal to n.
...a) Add value to BITree[index]
...b) Go to parent of BITree[index].  Parent can be obtained by removing
     the last set bit from index, i.e., index = index + (index & (-index))
 */


