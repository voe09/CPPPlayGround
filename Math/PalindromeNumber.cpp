/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, 
note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the 
problem "Reverse Integer", you know that the reversed integer might overflow. 
How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int dividor = 1;
        while (x / dividor >= 10) {
            dividor *= 10;
        }
        while (x > 0) {
            int head = x / dividor;
            int residual = x % 10;
            if (head != residual) return false;
            x -= head * dividor;
            x = (x - residual) / 10;
            dividor /= 100;
        }
        return true;
    }
};
