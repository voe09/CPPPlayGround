/*
Given a matrix of lower alphabets and a dictionary. 
Find all words in the dictionary that can be found in the matrix. 
A word can start from any position in the matrix and go left/right/up/down 
to the adjacent position. 

Example
Given matrix:
doaf
agai
dcan
and dictionary:
{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}


dog:
doaf
agai
dcan
dad:
doaf
agai
dcan
can:
doaf
agai
dcan
again:
doaf
agai
dcan
 */

class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        // write your code here
        Trie *tree = new Trie(board);
        vector<string> res;
        for (const auto &word : words) {
            if (tree->startWith(word)) {
                res.push_back(word);
            }
        }
        return res;
    }

private:
    class TreeNode {
    public:
        TreeNode() : childs(26, nullptr) {}

    public:
        vector<TreeNode*> childs;
    };

    class Trie {
    public:
        Trie(vector<vector<char>> &board) : root(new TreeNode) {
            int m = board.size(), n = board[0].size();
            vector<vector<bool>> visited (m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!visited[i][j]) {
                        visited[i][j] = true;
                        helper(board, visited, i, j, root);
                        visited[i][j] = false;
                    }
                }
            }
        }

        bool startWith(const string &s) {
            TreeNode *curr = root;
            for (const auto &c : s) {
                int idx = c - 'a';
                if (!curr->childs[idx]) return false;
                curr = curr->childs[idx];
            }
            return true;
        }

    private:
        void helper(vector<vector<char>> &board, vector<vector<bool>> &visited,
                    int i, int j, TreeNode *node) {
            int idx = board[i][j] - 'a';
            if (!node->childs[idx])
                node->childs[idx] = new TreeNode;
            node = node->childs[idx];
            int m = board.size(), n = board[0].size();
            vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (const auto &dir : dirs) {
                int x = i + dir.first, y = j + dir.second;
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (!visited[x][y]) {
                        visited[x][y] = true;
                        helper(board, visited, x, y, node);
                        visited[x][y] = false;
                    }
                }
            }
        }

    private:
        TreeNode *root;
    };
};



class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        // write your code here
        if (board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        vector<bool> searched (words.size(), false);
        vector<string> res;
        for (int w = 0; w < words.size(); ++w) {
            const string &word = words[w];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!searched[w] && board[i][j] == word[0] && !visited[i][j]) {
                        visited[i][j] = true;
                        if (helper(board, visited, i, j, word, 1)) {
                            searched[w] = true;
                            res.push_back(word);  
                        }
                        visited[i][j] = false;
                    }
                }
            }
        }
        return res;
    }

private:
    bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited,
            int i, int j, const string &word, int k) {
        if (k == word.size()) return true;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n
                && !visited[x][y] && board[x][y] == word[k]) {
                visited[x][y] = true;
                if (helper(board, visited, x, y, word, k + 1)) {
                    visited[x][y] = false;
                    return true;
                }
                visited[x][y] = false;
            }
        }
        return false;
    }
};


/*
题目变成给定一组word，检查哪个word可以由board形成。
如果还按照DFS回溯的方法，逐个检查每个word是否在board里，显然效率是比较低的。我们可以利用Trie数据结构，也就是前缀树。然后dfs时，如果当前形成的单词不在Trie里，就没必要继续dfs下去了。如果当前字符串在trie里，就说明board可以形成这个word。
 */

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};
