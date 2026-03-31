class Solution {
public:
    class DSU{
    public:
        vector<int> parent,rank;
        int count;
        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n,0);
            count=n;
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int find(int x)
        {
            if(x!=parent[x]) parent[x]=find(parent[x]);
            return parent[x];
        }
        void Union(int x,int y)
        {
            int px=find(x);
            int py=find(y);
            if(px!=py) count--;

            if(rank[px]<rank[py])
            {
                parent[px]=py;
                rank[py]++;
                
            }
            else 
            {
                parent[py]=px;
                rank[px]++;
            }
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
       
        DSU dsu(n);

        for(auto x:edges)
        {
            dsu.Union(x[0],x[1]);
        }
        return dsu.count;
    }
};
