/*
题目是RateLimit，允许每个客户在每秒内访问100次，
bool isAllowed(int clientID)
我说那我用Token Bucket吧
 */
#include <queue>
#include <unordered_map>
#include <time.h>
using namespace std;
class LogSys {
public:
    LogSys(int capacity) : capacity_(capacity) {
        time(&start_);   
    };

    bool isAllowed(int clientID) {
        time(&curr_);
        double diff = difftime(curr_, start_);
        if (capacity_ == 0) return false;
        if (!cache_.count(clientID)) {
            cache_[clientID].push(diff);
            return true;
        }
        else {
            auto &q = cache_[clientID];
            if (q.size() < capacity_) {
                q.push(diff);
                return true;
            } else {
                double prev_req = q.front();
                q.pop();
                q.push(diff);
                if (diff - prev_req < 60) {
                    return false;
                } else {
                    return true;
                }
            }
        }
    }

private:
    time_t start_;
    time_t current_;
    int capacity_;
    unordered_map<int, priority_queue<double>> cache_;
};


#include <time.h>
#include <iostream>
using namespace std;

class RateLimiter {
public:
    RateLimiter(int limit) : tokenPerSec(limit), capacity(limit), token(limit) {
        time(&prev);
    }

    bool take() {
        time(&curr);
        token += static_cast<int>(difftime(curr, prev) * tokenPerSec);
        if (token > capacity) token = capacity;
        --token;
        prev = curr;
        if (token < 0) return false;
        else return true;
    }

private:
    time_t prev, curr;
    int tokenPerSec;
    int capacity;
    int token;
};

void hello(RateLimiter &limiter) {
    if (limiter.take()) std::cout << "hello" << std::endl;
    else std::cout << "error" << std::endl;
}

int main() {
    RateLimiter limiter(3);
    for (int i = 0; i < 4; ++i) {
        hello(limiter);
    }

    for (int i = 0; i < 1000000000; ++i) {
        continue;
    }

    for (int i = 0; i < 4; ++i) {
        hello(limiter);
    }
}
