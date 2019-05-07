/*
Given an array of scores that are non-negative integers. 
Player 1 picks one of the numbers from either end of the array followed by the 
player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
 */

/*
There are two choices:
1. The user chooses the ith coin with value Vi: The opponent either chooses (i+1)th coin or jth coin. The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vi + min(F(i+2, j), F(i+1, j-1) )


2. The user chooses the jth coin with value Vj: The opponent either chooses ith coin or (j-1)th coin. The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vj + min(F(i+1, j-1), F(i, j-2) )

F(i, j)  represents the maximum value the user can collect from
         i'th coin to j'th coin.

    F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ),
                   Vj + min(F(i+1, j-1), F(i, j-2) ))
Base Cases
    F(i, j)  = Vi           If j == i
    F(i, j)  = max(Vi, Vj)  If j == i+1
 */
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

bool isWinner(vector<int> nums) {
    if (nums.empty()) return true;
    int n = nums.size();
    vector<vector<int>> dp (n, vector<int>(n, 0));
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0; i < n - gap; ++i) {
            if (gap == 0)
                dp[i][i + gap] = nums[i];
            else if (gap == 1)
                dp[i][i + gap] = max(nums[i], nums[i + gap]);
            else {
                int v = nums[i] + min(dp[i + 2][i + gap], dp[i + 1][i + gap - 1]);
                int w = nums[i + gap] + min(dp[i][i + gap - 2], dp[i + 1][i + gap - 1]);
                dp[i][i + gap] = max(v, w);
            }
        }
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return dp[0][n - 1] >= (sum - dp[0][n - 1]);
}

int main() {
    cout << isWinner({1, 5, 2}) << endl;
    cout << isWinner({1, 5, 233, 7}) << endl;
}
