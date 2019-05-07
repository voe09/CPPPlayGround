/*
You have 4 cards each containing a number from 1 to 9. 
You need to judge whether they could operated through *, /, +, -, (, ) 
to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. 
For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as
a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 
- 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2],
we cannot write this as 12 + 12.
 */

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<char> operators {'+', '-', '*', '/'};
        vector<double> doubles;
        for (const auto& num : nums) {
            doubles.push_back(num * 1.0);
        }
        return find24(doubles, operators);
    }

private:
    bool find24(vector<double>& nums, vector<char>& operators) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) <= 1e-6;
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                vector<double> res;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j)
                        res.push_back(nums[k]);
                }
                for (const auto& op : operators) {
                    if ((op == '+' || op == '*') && j < i) continue;
                    if (op == '/' && nums[j] == 0.0) continue;
                    double tmp;
                    if (op == '+') tmp = nums[i] + nums[j];
                    else if (op == '-') tmp = nums[i] - nums[j];
                    else if (op == '*') tmp = nums[i] * nums[j];
                    else tmp = nums[i] / nums[j];
                    res.push_back(tmp);
                    if (find24(res, operators)) return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
};


class Solution {
public:
double elipson = pow(10.0, -5);
vector<char> operations = {'+','-','*','/'};
bool judgePoint24(vector<int>& nums) {
    vector<double> vec;
    for(auto n : nums){
        vec.push_back(n*1.0);
    }
    return find24(vec);
}

bool find24(vector<double> vec){
    if(vec.size() == 1){
        return abs(vec[0] - 24.0) <= elipson;
    }
    for(int i = 0; i < vec.size(); ++i){//each time we pick up two number for computation
        for(int j = 0; j < vec.size(); ++j){
            if(i == j) continue;
            vector<double> res;
            for(int k = 0; k < vec.size(); ++k){
                if(k != i && k != j) res.push_back(vec[k]);
            }
            for(auto op : operations){
                if((op == '+' || op == '*') && i > j) continue;//no need to re-calculate
                if(op =='/'  && vec[j] == 0.0) continue;
                switch(op){
                    case '+': res.push_back(vec[i] + vec[j]); break;
                    case '-': res.push_back(vec[i] - vec[j]); break;
                    case '*': res.push_back(vec[i] * vec[j]); break;
                    case '/': res.push_back(vec[i] / vec[j]); break;
                }
                if(find24(res)) return true;
                res.pop_back();//!!!important
            }
        }
    }
    return false;
}
};
