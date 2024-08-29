class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        UnionFind un = UnionFind(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    un.unon(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (un.roots[i] == i) cnt++;
        }
        
        return n - cnt;
    }


private:

    struct UnionFind {
        UnionFind(int n) {
            for (int i = 0; i < n; i++) roots.push_back(i);
        }

        int find(int x) {
            if (roots[x] != x) roots[x] = find(roots[x]);
            return roots[x];
        }

        void unon(int x, int y) {
            int x_root = find(x), y_root = find(y);
            roots[y_root] = x_root;
        }
        vector<int> roots;
    };

};