/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists
in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

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
// http://www.geeksforgeeks.org/implement-lru-cache/

// Wrong implementation, list.erase only take iterator
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {

    }

    int get(int key) {
        if (lookup_.count(key)) {
            queue_.erase(key);
            queue_.push_front(key);
            return lookup_[key];
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (lookup_.count(key)) {
            lookup_[key] = value;
            queue_.erase(key);
            queue_.push_front(key); 
        } else {
            if (lookup_.size() == capacity_) {
                int tmp = queue_.back();
                queue_.pop_back();
                lookup_.erase(tmp);
                lookup_[key] = value;
                queue_.push_front(key);
            } else {
                lookup_[key] = value;
                queue.push_front(key);
            }
        }
    }

private:
    int capacity_;
    std::list<int> queue_;
    std::unordered_map<int, int> lookup_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


// Correct Implementation
class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        if (map_.find(key) != map_.end()) {
            // It key exists, update it.
            const auto value = map_[key]->second;
            update(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // If cache is full while inserting, remove the last one.
        if (map_.find(key) == map_.end() && list_.size() == capa_) {
            auto del = list_.back(); list_.pop_back();
            map_.erase(del.first);
        }
         update(key, value);
    }
    
private:
    list<pair<int, int>> list_; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
    int capa_;
    
    // Update (key, iterator of (key, value)) pair
    void update(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }
};
