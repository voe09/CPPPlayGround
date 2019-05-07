#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <iostream>
using namespace std;

class Random {
public:
    Random(vector<pair<string, int>> &bottles) : n(bottles.size()), total(0) {
        board.resize(n, 0);
        for (int i = 0; i < bottles.size(); ++i) {
            board[i] = total;
            m[i] = bottles[i].first;
            total += bottles[i].second;
        }
    }

    string getBottle() {
        int target = rand() % total;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (board[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return m[right];
    }

private:
    int n;
    int total;
    vector<int> board;
    unordered_map<int, string> m;
};

int main() {
    vector<pair<string, int>> bottles {{"a", 50}, {"b", 25}, {"c", 25}};
    Random r = Random(bottles);
    unordered_map<string, int> m;
    for (int i = 0; i < 100; ++i) {
        string tmp = r.getBottle();
        ++m[tmp];
    }

    for (const auto &pair : m) {
        std::cout << pair.first << "," << pair.second << std::endl;
    }
}
