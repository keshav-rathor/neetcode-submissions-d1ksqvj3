class UnionFind{
    public:
    vector<int> parent;
    vector<int> rank;
    int count;

    UnionFind(int n)
    {
        count=n;
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;

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
        if(px!=py)
        {
            if(rank[px]>=rank[py])
            {
                parent[py]=px;
                rank[px]++;

            }
            else 
            {
                parent[px]=py;
                rank[py]++;
            }
            count--;
        }
        
    }
    int get()
    {
        return count;
    }

};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind U_F(n);

        for(auto x:edges)
        {
            U_F.Union(x[0],x[1]);
        }

        return U_F.get();

    }
};
