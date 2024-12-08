class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0], right[n-1] = height[n-1];
        for (int i = 1; i < n; i++) {
            left[i] = max(height[i], left[i-1]);
            right[n - i - 1] = max(height[n - i - 1], right[n - i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(0, min(left[i], right[i]) - height[i]);
        }
        return res;
    }
};


// stack solution - much hard to understand
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            if (stk.empty() || height[stk.top()] >= height[i]) {
                stk.push(i);
            } else {
                while (!stk.empty() && height[stk.top()] < height[i]) {
                    int t = stk.top();
                    stk.pop();
                    if (stk.empty()) continue;
                    int dist = i - stk.top() - 1;
                    res += (min(height[stk.top()], height[i]) - height[t]) * dist;
                }
                stk.push(i);
            }
        }
        return res;
    }
};