/*
Implement functionality of hashmap with the following functions, all O(1) time:
put(K, V)
get(K) -> V
delete(K)
getRandom() -> K, V
*/
#include <unordered_map>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
using namespace std;

class HashMap {
public:
    HashMap() {}

    void put(int key, int val) {
        if (!m.count(key)) {
            cache.push_back({key, val});
            m[key] = (cache.size() - 1);
        }
        else {
            auto pos = m[key];
            cache[pos].second = val;
        }
    }

    int get(int key) {
        if (!m.count(key)) return -1;
        else {
            return cache[m[key]].second;
        }
    }

    void deleteKey(int key) {
        auto p1 = m[key];
        auto idx = cache.back().first;
        auto p2 = m[idx];
        swap(cache[p1], cache[p2]);
        cache.pop_back();
        m.erase(key);
        m[idx] = p1;
    }

    int getRandom() {
        return cache[rand() % cache.size()].second;
    }

private:
    unordered_map<int, int> m;
    vector<pair<int, int>> cache;
};

int main() {
    HashMap hp = HashMap();
    hp.put(1, 1);
    std::cout << hp.get(1) << std::endl;
    hp.put(1, 2);
    std::cout << hp.get(1) << std::endl;
    hp.put(2, 1);
    std::cout << hp.get(1) << std::endl;
    std::cout << hp.get(2) << std::endl;
    hp.deleteKey(1);
    std::cout << hp.get(1) << std::endl;
    hp.put(3, 3);
    hp.put(4, 4);
    hp.put(5, 4);
    hp.put(6, 5);
    std::cout << hp.getRandom() << std::endl;
}
