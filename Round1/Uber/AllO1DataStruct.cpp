/*
Implement a data structure supporting the following operations:

 

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
 

Challenge: Perform all these in O(1) time complexity.
*/
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
#include <iostream>
using namespace std;


class DataStr {
public:
    DataStr() {}

    void Inc(string key) {
        if (!m.count(key)) {
            if (cache.empty() || cache.back().freq != 1) {
                cache.emplace_back(key, 1);
            } else {
                cache.back().keys.insert(key);
            }
            m[key] = (--cache.end());
        } else {
            auto prev = m[key];
            --prev;
            auto curr = m[key];
            curr->keys.erase(key);
            if (prev == cache.end() || prev->freq != curr->freq + 1) {
                Bucket newBucket(key, curr->freq + 1);
                auto tmp = cache.insert(curr, newBucket);
                m[key] = tmp;
            } else {
                prev->keys.insert(key);
                m[key] = prev;
            }
            if (curr->keys.empty()) cache.erase(curr);
        }
    }

    void Dec(string key) {
        if (!m.count(key)) return;
        auto curr = m[key];
        if (curr->freq == 1) {
            curr->keys.erase(key);
            if (curr->keys.empty()) {
                cache.erase(curr);
            }
            m.erase(key);
        } else {
            curr->keys.erase(key);
            auto next = curr;
            ++next;
            if (next == cache.end() || next->freq != curr->freq - 1) {
                Bucket newBucket(key, curr->freq - 1);
                auto tmp = cache.insert(next, newBucket);
                m[key] = tmp;
            } else {
                next->keys.insert(key);
                m[key] = next;
            }
            if (curr->keys.empty()) cache.erase(curr);
        }
    }

    string GetMaxKey() {
        if (cache.empty()) return "";
        else return *(cache.front().keys.begin());
    } 

    string GetMinKey() {
        if (cache.empty()) return "";
        else return *(cache.back().keys.begin());
    }

private:
    struct Bucket {
        int freq;
        unordered_set<string> keys;
        Bucket(string key, int frequence) : keys({key}), freq(frequence) {}
    };

    list<Bucket> cache;
    unordered_map<string, list<Bucket>::iterator> m;
};

int main() {
    DataStr storage;
    storage.Inc("A");
    cout << storage.GetMaxKey() << endl;
    cout << storage.GetMinKey() << endl;
    storage.Dec("B");
    storage.Dec("A");
    cout << storage.GetMaxKey() << endl;
    cout << storage.GetMinKey() << endl;
    storage.Inc("A");
    storage.Inc("A");
    storage.Inc("A");
    storage.Inc("A");
    storage.Inc("B");
    storage.Inc("B");
    storage.Inc("B");
    storage.Inc("C");
    storage.Inc("C");
    storage.Inc("D");
    cout << storage.GetMaxKey() << endl;
    cout << storage.GetMinKey() << endl;
    storage.Dec("D");
    cout << storage.GetMinKey() << endl;
    storage.Dec("C");
    storage.Dec("C");
    cout << storage.GetMinKey() << endl;
    storage.Dec("A");
    storage.Dec("A");
    cout << storage.GetMaxKey() << endl;
}
