class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (cycle(adj, 0, -1, vis)) return false;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) return false;
        }

        return true;
    }

    bool cycle(vector<vector<int>>& adj, int i, int parent, vector<int>& vis) {
        vis[i] = 1;

        for (int neighbor : adj[i]) {
            if (!vis[neighbor]) {
                if (cycle(adj, neighbor, i, vis)) return true;
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }
};
