Implement pow(x, n).

// Iterative solution.
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        long long abs_n = abs(static_cast<long long>(n));
        while (abs_n > 0) {
            if (abs_n & 1) {
                result *= x;
            }
            abs_n >>= 1;
            x *= x;
        }
        return n < 0 ? 1 / result : result;
    }
};

// Time:  O(logn) = O(1)
// Space: O(logn) = O(1)
// Recursive solution.
class Solution2 {
public:
    double myPow(double x, int n) {
        if (n < 0 && n != -n) {
            return 1.0 / myPow(x, -n);
        }
        if (n == 0) {
            return 1;
        }
        double v = myPow(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        } else {
            return v * v * x;
        }
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        int sign = (x > 0 || n % 2 == 0) ? 1 : -1;
        x = std::abs(x);
        double res = n * std::log(x);
        res = std::exp(res);
        return sign * res;
    }
};



nest myPow
double myPow(double x, int n) {
    if(n<0) return 1/x * myPow(1/x, -(n+1));
    if(n==0) return 1;
    if(n==2) return x*x;
    if(n%2==0) return myPow( myPow(x, n/2), 2);
    else return x*myPow( myPow(x, n/2), 2);
}
double myPow
double myPow(double x, int n) { 
    if(n==0) return 1;
    double t = myPow(x,n/2);
    if(n%2) return n<0 ? 1/x*t*t : x*t*t;
    else return t*t;
}
double x
double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}
iterative one
double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0) {
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}


class Solution {
public:
    double pow(double x, int n) {
        if(n<0){
            x = 1.0/x;
            n = -n;
        }
        int unsigned m = n;
        double tbl[32] = {0};
        double result = 1;
        tbl[0] = x;
        for(int i=1;i<32;i++){
            tbl[i] = tbl[i-1]*tbl[i-1];
        }
        for(int i=0;i<32;i++){
            if( m & (0x1<<i) )
            result *= tbl[i];
        }
        return result;
    }
};
