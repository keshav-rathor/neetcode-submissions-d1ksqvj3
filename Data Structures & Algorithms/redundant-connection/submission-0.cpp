class UnionFind {
public:
    vector<int> rank;
    vector<int> parent;

    UnionFind(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (uf.find(u) == uf.find(v)) {
                return edge;
            } else {
                uf.Union(u, v);
            }
        }

        return {};
    }
};
