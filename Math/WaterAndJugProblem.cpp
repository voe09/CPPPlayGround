/*
You are given two jugs with capacities x and y litres. There is an infinite 
amount of water supply available. You need to determine whether it is possible
to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained 
within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full 
or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
*/

// d 是 gcd(x, y)的倍数, d <= x + y即可

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        int d = gcd(x, y);
        if (z <= (x + y) && z % d == 0) return true;
        else return false;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
};
