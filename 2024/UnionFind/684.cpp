class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf = UnionFind{};
        for (vector<int> &edge : edges) {
            int x = edge[0], y = edge[1];
            if (uf.find(x) == uf.find(y)) return edge;
            uf.unon(x, y);
        }
        return {};
    }

private:
    struct UnionFind {
        int find(int x) {
            if (!m.count(x) || m[x] == x) return x;
            int root_x = find(m[x]);
            m[x] = root_x;
            return root_x;
        }

        void unon(int x, int y) {
            int root_x = find(x), root_y = find(y);
            m[root_y] = root_x;
        }

        unordered_map<int, int> m;
    };
};