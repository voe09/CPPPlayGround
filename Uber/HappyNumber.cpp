/*
Is happy numer or not
 */

#include <unordered_set>
#include <iostream>
using namespace std;


bool isHappy(int n) {
    unordered_set<int> s;
    while (n > 1) {
        int t = 0;
        while (n > 0) {
            t += (n % 10) * (n % 10);
            n /= 10;
        }
        if (s.count(t)) break;
        s.insert(t);
        n = t;
    }
    return n == 1;
}

int main() {
    std::cout << isHappy(1) << std::endl;
    std::cout << isHappy(19) << std::endl;
    std::cout << isHappy(4) << std::endl;
}
