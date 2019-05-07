/*
There are people sitting in a circular fashion, print every third member while removing them, the next counter starts immediately after the member is removed. Print till all the members are exhausted.
For example:
Input: consider 123456789 members sitting in a circular fashion,
Output: 369485271
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> CircularCounter(vector<int> &nums) {
    if (nums.empty()) return {};
    int cnt = 0;
    queue<int> q;
    for (const auto &num : nums) {
        q.push(num);
    }
    vector<int> res;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        ++cnt;
        if (cnt % 3 == 0) res.push_back(tmp);
        else {
            q.push(tmp);
        }
    }

    return res;
}

int main() {
    vector<int> inputs {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> res = CircularCounter(inputs);
    for (const auto &num : res) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


a = ['1','2','3','4','5','6','7','8','9']

def josepheus(int_list, skip):
  skip = skip - 1 #list starts with 0 index
  idx = 0
  while len(int_list)>0:
    idx = (skip+idx)%len(int_list) #hashing to keep changing the index to every 3rd
    print int_list.pop(idx)


josepheus(a,3)
