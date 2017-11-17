/*
Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. 
           Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
           decrements an existing key by 1. If the key does not exist, this
           function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, 
              return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, 
              return an empty string "".
Challenge: Perform all these in O(1) time complexity.
 */
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!m_.count(key)) {
            if (cache_.empty() || cache_.back().cnt_ != 1) {
                auto newBucket = cache_.insert(cache_.end(), {1, {key}});
                m_[key] = newBucket;
            } else {
                auto bucket = --cache_.end();
                bucket->keys_.insert(key);
                m_[key] = bucket;
            }
        }
        else {
            auto bucket = m_[key];
            int cnt = bucket->cnt_;
            bucket->keys_.erase(key);
            auto nextBucket = --bucket;
            if (nextBucket != cache_.end() && nextBucket->cnt_ == cnt + 1) {
                nextBucket->keys_.insert(key);
                m_[key] = nextBucket;
            } else {
                auto newBucket = cache_.insert(bucket, {cnt + 1, {key}});
                m_[key] = newBucket;
            }
            if (bucket->keys_.empty()) cache_.erase(bucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m_.count(key)) return;
        auto bucket = m_[key];
        int cnt = bucket->cnt_;
        if (bucket->cnt_ == 1) {
            bucket->keys_.erase(key);
            m_.erase(key);
        } else {
            bucket->keys_.erase(key);
            auto prevBucket = ++bucket;
            if (prevBucket->cnt_ == cnt - 1) {
                prevBucket->keys_.insert(key);
                m_[key] = prevBucket;
            } else {
                auto newBucket = cache_.insert(prevBucket, {cnt - 1, {key}});
                m_[key] = newBucket;
            }
        }
        if (bucket->keys_.empty()) cache_.erase(bucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
       return cache_.empty() ? "" : *(cache_.begin()->keys_.begin()); 
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return cache_.empty() ? "" : *(cache_.rbegin()->keys_.begin());
    }

private:
    struct Bucket {
        int cnt_;
        unordered_set<string> keys_;
    };
    unordered_map<string, list<Bucket>::iterator> m_;
    list<Bucket> cache_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
