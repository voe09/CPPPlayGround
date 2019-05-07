/* LRU cache
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists
            in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
                When the cache reached its capacity, it should invalidate the 
                least recently used item before inserting a new item.
 */

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) : capacity_(capacity) {
        // do intialization if necessary
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if (!m_.count(key)) return -1;
        auto iter = m_[key];
        cache_.splice(cache_.begin(), cache_, iter);
        return iter->second;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (m_.count(key)) {
            auto iter = m_[key];
            iter->second = value;
            cache_.splice(cache_.begin(), cache_, iter);
            return;
        }
        if (m_.size() >= capacity_) {
            pair<int, int> tmp = cache_.back();
            m_.erase(tmp.first);
            cache_.pop_back();
            cache_.emplace_front(key, value);
            m_[key] = cache_.begin();
        } else {
            cache_.emplace_front(key, value);
            m_[key] = cache_.begin();
        }
    }

private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
};

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) : capacity_(capacity) {
        // do intialization if necessary
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        auto iter = m_.find(key);
        if (iter == m_.end()) return -1;
        cache_.splice(cache_.begin(), cache_, iter->second);
        return iter->second->second;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        auto iter = m_.find(key);
        if (iter != m_.end()) {
            iter->second->second = value;
            cache_.splice(cache_.begin(), cache_, iter->second);
        }

        else {
            if (m_.size() == capacity_) {
                auto &node = cache_.back();
                m_.erase(node.first);
                cache_.pop_back();
            }
            cache_.emplace_front(key, value);
            m_[key] = cache_.begin();
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    list<pair<int, int>> cache_;
    int capacity_;
};
