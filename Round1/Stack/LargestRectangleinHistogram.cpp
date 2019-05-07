/*
Given n non-negative integers representing the histogram's bar height 
where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

// 下面这个解法不行
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int height = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                height = min(height, heights[j]);
                int width = j - i + 1;
                res = max(res, height * width);
            }
        }
        return res;
    }
};

class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            
            int ret = 0;
            height.push_back(0);
            vector<int> index;
            
            for(int i = 0; i < height.size(); i++)
            {
                while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();
                    
                    int sidx = index.size() > 0 ? index.back() : -1;
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                }
                index.push_back(i);
            }
            
            return ret;
        }
    };
