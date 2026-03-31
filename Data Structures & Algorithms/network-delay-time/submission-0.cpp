class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for(auto x: times) {
            int u = x[0] - 1;
            int v = x[1] - 1;
            int t = x[2];
            adj[u].push_back({v, t});
        }

        dist[k-1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int node = x.second;
            int currDist = x.first;

            for (auto [next, wt] : adj[node]) {
                if (currDist + wt < dist[next]) {
                    dist[next] = currDist + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int maxDist = *max_element(dist.begin(), dist.end());
        return (maxDist == INT_MAX) ? -1 : maxDist;
    }
};
