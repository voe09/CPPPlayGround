/*
There is a room with n lights which are turned on initially and 4 buttons on the
wall. After performing exactly m unknown operations towards buttons, you need 
to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 
buttons are given below:

You can flip all the lights.
You can flip lights with even numbers.
You can flip lights with odd numbers.
You can flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
Have you met this question in a real interview? Yes
Example
Given n = 1, m = 1.
return 2 // Status can be: [on], [off]

Given n = 2, m = 1.
return 3 // Status can be: [on, off], [off, on], [off, off]
 */

class Solution {
public:
    /*
     * @param : number of lights
     * @param : number of operations
     * @return: the number of status
     */
    int flipLights(int n, int m) {
        // write your code here
        int marker = 0;
        for (int i = 0; i < n; ++i) {
            marker += (1 << i);
        }

        vector<int> ops;
        // Flip all
        ops.push_back(marker);
        // Flip odd
        int odd = 0;
        for (int i = 0; i < n; i += 2) {
            odd += (1 << i);
        }
        ops.push_back(odd);

        int even = 0;
        for (int i = 1; i < n; i += 2) {
            even += (1 << i);
        }
        ops.push_back(even);

        int four = 0;
        for (int i = 0; (3 * i + 1) < n; ++i) {
            four += (1 << (3 * i + 1));
        }
        ops.push_back(four);

        unordered_set<int> visited;
        int res = 0;
        helper(marker, m, ops, visited, res);
        return res;
    }

private:
    void helper(int marker, int m, vector<int>& ops,
            unordered_set<int>& visited, int& res) {
        if (m == 0) {
            if (!visited.count(marker)) {
                ++res;
                visited.insert(marker);
            }
            return;
        }

        for (const auto& op : ops) {
            helper(marker ^ op, m - 1, ops, visited, res);
        }
        return;
    }
};
