/*
Square root of an integer
 */
#include <iostream>
using namespace std;


int SquareRoot(int n) {
    if (n <= 1) return n;
    int left = 1, right = n / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == n / mid) return mid;
        if (mid < n / mid) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cout << i << ": " << SquareRoot(i) << endl;
    }
}


double SquareRoot(int n, int k) {
    if (n <= 1) return n;
    double epsilon = 1;
    while (k) {
        epsilon /= 10;
        --k;
    }

    double res = 0;
    double diff = 1;
    while (diff > epsilon) {
        double tmp = res - (res * res - n) / (2 * res);
        diff = abs(res - tmp);
        res = tmp;
    }

    return res;
}
