/*
Given n non-negative integers representing the histogram's bar height
where the width of each bar is 1, find the area of largest rectangle
in the histogram.

histogram

Above is a histogram where width of each bar is 1, 
given height = [2,1,5,6,2,3].

histogram

The largest rectangle is shown in the shaded area, 
which has area = 10 unit.

Example
Given height = [2,1,5,6,2,3],
return 10.
 */

class Solution {
public:
    /*
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i + 1 < height.size() && height[i] <= height[i + 1]) continue;
            int minH = height[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, height[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};

/*
这里维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值，
当当前值小于栈顶值时，取出栈顶元素，然后计算当前矩形面积，
然后再对比当前值和新的栈顶值大小，若还是栈顶值大，则再取出栈顶，
算此时共同矩形区域面积，照此类推，可得最大矩形。代码如下：
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int cur = s.top(); s.pop();
                res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};
