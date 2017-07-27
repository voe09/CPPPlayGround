/*
There is a list of sorted integers from 1 to n. Starting from left to right, 
remove the first number and every other number afterward 
until you reach the end of the list.

Repeat the previous step again, but this time from right to left, 
remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, 
until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
 */

// http://www.cnblogs.com/grandyang/p/5860706.html

class Solution {
public:
    int lastRemaining(int n) {
                
    }
};


/*
我们可以发现从左往右删的时候，每次都是删掉第一个数字，而从右往左删的时候，
则有可能删掉第一个或者第二个数字，而且每删一次，数字之间的距离会变为之前的两倍。
我们要做的是每次记录当前数组的第一个数字，而且我们再通过观察可以看出，从右往左删时，
如果剩下的数字个数是偶数个时，删掉的是第二个数字；如果是奇数个的时候，删掉的是第一个数字
 */

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;

        for (int step = 2, direction = 1; n > 1;
             n /= 2, step *= 2, direction *= -1) {

            start += direction * (step * (n / 2) - step / 2);
        }

        return start;
    }
};
