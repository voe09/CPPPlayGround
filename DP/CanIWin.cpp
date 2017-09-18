/*
In the "100 game," two players take turns adding, to a running total, any 
integer from 1..10. The player who first causes the running total to reach
or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers
of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine
if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and
desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
 */

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

    }
};



 class Solution {
 public:
 	bool canIWin(int maxChoosableInteger, int desiredTotal) {
 		if(desiredTotal == 0) return true;

 		if((maxChoosableInteger+1) * maxChoosableInteger / 2 < desiredTotal)
 			return false;

 		unordered_map<int, bool> dp;

 		// a bit in record being equal to 1 means a number is available
 		// for example if record is ..1000, it means number 3 has not been used,
 		// for convenience we do not use the least significant digit.
 		int record = 0;
 		for(int i = 0; i < maxChoosableInteger+1; i++) {
 			record = (record << 1) + 1;
 		}
 		return f(desiredTotal, record, dp);
 	}

 	bool f(int dt, int record, unordered_map<int, bool> &dp)
 	{
 		if(dp.count(record)) {
 			return dp[record];
 		}

 		// we know maxChoosableInteger wont be larger than 20
 		for(int i = 20; i > 0; i--) {
 			int bit = 1 << i;

 			// if this number has not been used
 			if(record & bit) {
 				if(i >= dt) {
 					dp[i] = true;
 					return true;
 				}
 				// mark number i so it has been used and check whether the opponent
 				// can win. Notice that due to the annoyance of [] operator
 				// automatically inserting value into a set in c++, we should not
 				// use dp[...] = f(..., dp) to avoid changing dp BEFORE the
 				// function is called.
 				bool t = f(dt-i, record^bit, dp);
 				dp[record^bit] = t;
 				if(t == false) {
 					return true;
 				}
 			}
 		}
 		return false;

 	}

 };



class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used)) return m[used];
        for (int i = 0; i < length; ++i) {
            int cur = (1 << i);
            if ((cur & used) == 0) {
                if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};
