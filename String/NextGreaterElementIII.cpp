/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer
which has exactly the same digits existing in the integer n and is greater 
in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int target;
        bool permutable = false;
        for (int i = num.size() - 1; i >= 1; --i) {
            if (num[i] > num[i - 1]) {
                target = i - 1;
                permutable = true;
                break;
            }
        }
        if (!permutable) return -1;
        int swap_target;
        for (int i = num.size() - 1; i > target; --i) {
            if (num[target] < num[i]) {
                swap_target = i;
                break;
            }
        }
        std::swap(num[target], num[swap_target]);
        std::reverse(num.begin() + target + 1, num.end());
        string max = to_string(INT_MAX);
        if (num.size() == max.size()) {
            for (int i = 0; i < num.size(); ++i) {
                if (num[i] > max[i]) return -1;
            }
        }
        return stoi(num);
    }
};
