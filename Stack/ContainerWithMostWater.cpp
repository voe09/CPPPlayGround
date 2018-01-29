/*
Given n non-negative integers a1, a2, ..., an, where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

 Notice

You may not slant the container.

Have you met this question in a real interview? Yes
Example
Given [1,3,2], the max area of the container is 2.
 */

class Solution {
public:
    /*
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int left = 0, right = heights.size() - 1;
        int res = 0;
        while (left < right) {
            int height = min(heights[left], heights[right]);
            res = max(res, (right - left) * height);
            heights[left] < heights[right] ? ++left : --right;
        }
        return res;
    }
};
