class Solution {
public:
    int dist(vector<int> p1, vector<int> p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = dist(points[i], points[j]);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> vis(n, 0);
        int cost = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();  
            pq.pop();

            if (vis[node] == 1) continue;
            
            vis[node] = 1;
            cost += wt;

            for (auto [u, n_wt] : adj[node]) {
                if (vis[u] == 0) {
                    pq.push({n_wt, u});
                }
            }
        }

        return cost;
    }
};
