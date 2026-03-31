class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto x : pre) {
            adj[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (detectCycle(i, adj, vis)) return false;
            }
        }

        return true;
    }

    bool detectCycle(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[node] == 1) return true;
        if (vis[node] == 2) return false;

        vis[node] = 1;
        for (auto neighbor : adj[node]) {
            if (detectCycle(neighbor, adj, vis)) return true;
        }
        vis[node] = 2;
        return false;
    }
};
