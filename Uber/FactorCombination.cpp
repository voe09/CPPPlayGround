/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 

Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
 

Examples: 
input: 1
output: 

[]
input: 37
output: 

[]
input: 12
output:

[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:

[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
#include <vector>
#include <iostream>
using namespace std;

void helper(int n, int start, vector<int> &curr, vector<vector<int>> &res) {
    if (n == 1) {
        if (curr.size() > 1)
            res.push_back(curr);
        return;
    }

    for (int i = start; i <= n; ++i) {
        if (n % i == 0) {
                curr.push_back(i);
                helper(n / i, i, curr, res);
                curr.pop_back();
        }
    }
}

vector<vector<int>> FactorCombination(int n) {
    if (n <= 2) return {};
    vector<vector<int>> res;
    vector<int> curr;
    helper(n, 2, curr, res);
    return res;
}

int main() {
    auto res = FactorCombination(8);
    for (const auto &vec : res) {
        for (const auto &num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}
