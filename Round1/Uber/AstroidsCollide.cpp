/*
Given input array of astroid size and its direction (left:positive or right:negative), 
find out what will be the result or remaining astroid after their collision.
Example1] Astroid: {-6, 4, 10,}
-6: Astroid of size 6 pound moving in direction right.
4: Astroid of size 4 pound moving in direction left.
-6 will collide with 4 and results in {-6, 10}
-6 collide with 10 and results in {10}
Ans: {10}
Example 2] Astroid: {10, -8, 15,}
10 will collide with -8 and results in {10, 15}
Ans: {10,15} as both traveling to left direction.
*/
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> AstroidCollision(vector<int> &astroids) {
    if (astroids.empty()) return {};
    stack<int> stk;
    for (const auto &astroid : astroids) {
        if (stk.empty() || (stk.top() * astroid > 0)) {
            stk.push(astroid);
        }
        else {
            while (!stk.empty() && abs(stk.top()) < abs(astroid)) {
                stk.pop();
            }
            if (stk.empty()) stk.push(astroid);
        }
    }
    vector<int> res;
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

int main() {
    vector<int> inputs {-6, 4, 10};
    auto res = AstroidCollision(inputs);
    for (const auto &num : res) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
