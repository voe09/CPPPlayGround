class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
        head = new Node(-1, -1);
        tail = new Node(-2, -2);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        Node* t = getNode(key);
        return t == nullptr ? -1 : t->val;
    }

    void put(int key, int value) {
        Node* t = getNode(key);
        if (t == nullptr) {
            Node* tmp = new Node(key, value);
            cache[key] = tmp;
            Node* h = head->next;
            head->next = tmp;
            tmp->prev = head;
            tmp->next = h;
            h->prev = tmp;
            curr++;
        } else {
            t->val = value;
        }

        if (curr > cap) {
            Node* t = tail->prev;
            Node* pt = t->prev;
            pt->next = tail;
            tail->prev = pt;
            cache.erase(t->k);
            curr--;
        }
    }

private:
    struct Node {
        int val;
        int k;
        Node *prev, *next;
        Node(int k, int v) : k(k), val(v), prev(nullptr), next(nullptr) {}
    };

    Node* getNode(int key) {
        if (cache.count(key)) {
            Node* t = cache[key];
            Node *p = t->prev, *n = t->next;
            p->next = n;
            n->prev = p;
            Node* h = head->next;
            head->next = t;
            t->prev = head;
            t->next = h;
            h->prev = t;
            return t;
        } else {
            return nullptr;
        }
    }

    unordered_map<int, Node*> cache;
    Node *head, *tail;
    int cap;
    int curr;

    void print() {
        Node *t = head;
        while (t) {
            cout << "(" << t->k << ',' << t->val << ")";
            t = t->next;
        }
        cout << endl;
    }

    void printReverse() {
        Node *t = tail;
        while (t) {
            cout << "(" << t->k << ',' << t->val << ")";
            t = t->prev;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */