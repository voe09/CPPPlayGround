/*
给一个函数 返回一个人的所有friends，写一个函数返回不是friend的人共同好友最多的top k。。
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class User {
public:
    string name;
    vector<User*> friends;
    User(string s) : name(s) {}
};

struct Comp {
    bool operator() (pair<User*, int> &a, pair<User*, int> &b) {
        return a.second > b.second;
    }
};

vector<User*> TopKFriendsRec(User *root, int k) {
    unordered_map<User*, int> lookup;
    queue<pair<User*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        if (tmp.second < 2) {
            auto friends = tmp.first->friends;
            for (const auto &f : friends) {
                q.push({f, tmp.second + 1});
            }
        } else {
            ++lookup[tmp.first];
        }
    }

    priority_queue<pair<User*, int>, vector<pair<User*, int>>, Comp> pq;
    for (const auto &p : lookup) {
        if (pq.size() < k)
            pq.push({p.first, p.second});
        else {
            if (pq.top().second < p.second) {
                pq.pop();
                pq.push({p.first, p.second});
            }
        }
    }

    vector<User*> res;
    while (!pq.empty()) {
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}

int main() {
    User *a = new User("john");
    User *b = new User("alex");
    User *c = new User("sai");
    User *d = new User("adam");
    User *e = new User("Kate");
    User *f = new User("Ning");
    a->friends.push_back(b);
    a->friends.push_back(c);
    b->friends.push_back(d);
    b->friends.push_back(e);
    c->friends.push_back(d);
    c->friends.push_back(f);
    auto res = TopKFriendsRec(a, 1);
    cout << res[0]->name << endl;
}
