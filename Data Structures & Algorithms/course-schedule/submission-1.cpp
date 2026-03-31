class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto x : pre) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (detectCycle(i, adj, vis)) return false;
            }
        }

        return true;
    }

    bool detectCycle(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto neighbor : adj[node]) {
            if (vis[neighbor] == 1) return true;
            if (vis[neighbor] == 0) {
                if (detectCycle(neighbor, adj, vis)) return true;
            }
        }
        vis[node] = 2;
        return false;
    }
};
