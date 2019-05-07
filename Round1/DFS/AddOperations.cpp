/*
Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, -, or * 
between the digits so they evaluate to the target value.

Have you met this question in a real interview? Yes
Example
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
 */

class Solution {
public:
    /*
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        // write your code here
        stack<int> stk;
        string comb;
        vector<string> res;
        helper(num, 0, target, stk, comb, res);
        return res;
    }

private:
    bool isNum(char &c) {
        return c >= '0' && c <= '9';
    }

    void helper(string &num, int idx, int target, string &comb, vector<string> &res) {
        
    }
};
