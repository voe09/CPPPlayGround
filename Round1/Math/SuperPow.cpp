/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is 
an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
*/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (const auto& digit : b) {
            result = myPow(result, 10, 1337) * myPow(a, digit, 1337) % 1337;
        }
        return result;
    }

private:
    int myPow(int a, int n, int b) {
        int result = 1;
        int x = a % b;
        while (n) {
            if (n & 1) {
                result = result * x % b;
            }
            n >>= 1;
            x = x * x % b;
        }
        return result % b;
    }
};


class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
    }
    int pow(int x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x % 1337;
        return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
    }
};
