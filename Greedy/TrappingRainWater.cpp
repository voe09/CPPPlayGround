/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!
 */

/*
An element of array can store water if there are higher bars on left and right. 
We can find amount of water to be stored in every element by finding the heights 
of bars on left and right sides. The idea is to compute amount of water that can
be stored in every element of array. For example, consider the array {3, 0, 0, 2, 0, 4}, 
we can store two units of water at indexes 1 and 2, 
and one unit of water at index 2.

A Simple Solution is to traverse every array element and 
find the highest bars on left and right sides. Take the smaller of two heights. 
The difference between smaller height and height of current element is the 
amount of water that can be stored in this array element. Time complexity of this solution is O(n2).

An Efficient Solution is to prre-compute highest bar on left and right of every 
bar in O(n) time. Then use these pre-computed values to find the amount of water 
in every array element. Below is C++ implementation of this solution.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int res = 0;
        int h_left = height[0];
        int h_right = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left[i] = h_left;
            h_left = max(height[i], h_left);
        }

        for (int i = n - 2; i >= 0; --i) {
            right[i] = h_right;
            h_right = max(height[i], h_right);
        }

        for (int i = 1; i < n - 1; ++i) {
            int h_min = min(left[i], right[i]);
            if (h_min > height[i]) {
                res += h_min - height[i];
            }
        }
        
        return res;
    }
};
