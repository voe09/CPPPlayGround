/*
Given a string of numbers and operators, return all possible results from 
computing all the different possible ways to group numbers and operators. 
The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
 */

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return {};
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                string left = input.substr(0, i);
                string right = input.substr(i + 1);
                vector<int> left_res = diffWaysToCompute(left);
                vector<int> right_res = diffWaysToCompute(right);
                for (int j = 0; j < left_res.size(); ++j) {
                    for (int k = 0; k < right_res.size(); ++k) {
                        if (input[i] == '+') res.push_back(left_res[j] + right_res[k]);
                        else if (input[i] == '-') res.push_back(left_res[j] - right_res[k]);
                        else res.push_back(left_res[j] * right_res[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};
