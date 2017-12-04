/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class LRUCache {
public:
    LRUCache(int c) : capacity(c) {}

    int get(int key) {
        if (!m.count(key)) return -1;
        auto iter = m[key];
        cache.splice(cache.begin(), cache, iter);
        return iter->second;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            auto iter = m[key];
            cache.splice(cache.begin(), cache, iter);
            iter->second = value;
        } else {
            if (m.size() == capacity) {
                auto delKey = cache.back().first;
                cache.pop_back();
                m.erase(delKey);
                cache.push_front({key, value});
                m[key] = cache.begin();
            } else {
                cache.push_front({key, value});
                m[key] = cache.begin();
            }
        }
    }

private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(1, 4);
    cout << cache.get(1) << endl;
    cache.put(2, 5);
    cout << cache.get(3) << endl;
}
