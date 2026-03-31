class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);  // Path compression
            return parent[x];
        }

        bool unite(int x, int y) {  // ✅ Renamed from `union` to `unite`
            int px = find(x);
            int py = find(y);
            if (px == py) return false;

           
            if (rank[px] > rank[py]) 
            {
                parent[py] = px;
                rank[px]++; 
            } 
            else 
            {
                parent[px] = py;
                rank[py]++; 
            }
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);

        for (auto x : edges) {
            if (!dsu.unite(x[0], x[1])) return x;  
        }
        return {};
    }
};
