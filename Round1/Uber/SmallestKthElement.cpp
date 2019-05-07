/*
Smallest K Elements of Array
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> KSmallestElements(vector<int> &nums, int k) {
    priority_queue<int> q;
    for (const auto &num : nums) {
        if (q.size() < k) q.push(num);
        else {
            if (q.top() > num) {
                q.pop();
                q.push(num);
            }
        }
    }

    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.top());
        q.pop();
    }
    return res;
}

int main() {
    vector<int> nums {2, 4, 5, 62, 3, 1, 5, 7, 0};
    auto res = KSmallestElements(nums, 3);
    for (const auto &num : res) {
        cout << num << " ";
    }
    cout << endl;
}
