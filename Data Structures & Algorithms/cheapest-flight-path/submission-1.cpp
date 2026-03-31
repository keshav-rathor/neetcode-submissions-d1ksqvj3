class Solution {
public:
    
    
    int findCheapestPrice(int n, vector<vector<int>>& nums, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> map;

        for(auto x:nums)
        {
            map[x[0]].push_back({x[1],x[2]});
        }
        dist[src]=0;
        queue<pair<int,int>> q;

        q.push({src,0});
        while(!q.empty() && k-->=0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto val=q.front();
                q.pop();
                int cost=val.second;
                int node=val.first;
                for(auto x:map[node])
                {
                    if(dist[x.first]>cost+x.second)
                    {
                        dist[x.first]=cost+x.second;
                        q.push({x.first,dist[x.first]});
                    }
                    
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];


    }
};



