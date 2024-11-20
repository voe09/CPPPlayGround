class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node *trie = new Node();
        for (string &product : products) trie->index(product);
        vector<vector<string>> res;
        string prefix;
        for (char c : searchWord) {
            prefix.push_back(c);
            res.push_back(trie->search(prefix));
        }
        return res;
    }

private:
    struct Node {
        Node(): childs(26, nullptr), hasToken(false) {}
        void index(string &s) {
            Node *t = this;
            for (char c : s) {
                if (!t->childs[c-'a']) t->childs[c-'a'] = new Node();
                t = t->childs[c-'a'];
            }
            t->hasToken = true;
        } 


        vector<string> search(string &s) {
            Node *t = this;
            string prefix;
            vector<string> res;
            for (char c : s) {
                if (!t->childs[c-'a']) return res;
                prefix.push_back(c);
                t = t->childs[c-'a'];
            }
            
            helper(t, prefix, res);
            return res;
        }

        void helper(Node *t, string &prefix, vector<string> &res) {
            if (res.size() >= 3) return;
            if (t->hasToken) {
                res.push_back(prefix);
            }

            for (int i = 0; i < 26; i++) {
                if (!t->childs[i]) continue;
                prefix.push_back('a' + i);
                helper(t->childs[i], prefix, res);
                prefix.pop_back();
            }
        }

        vector<Node*> childs;
        bool hasToken;
    };
};