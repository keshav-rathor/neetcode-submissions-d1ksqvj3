class UnionFind
{
    public: 
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n)
    {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int find(int x)
    {
        if(parent[x]!=x) parent[x] = find(parent[x]);;
        return parent[x]; 
    }
    bool _union(int x,int y)
    {
        int px=find(x);
        int py=find(y);

        if(px==py) return false;
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
            rank[py]++;
        }
        else if(rank[px]>=rank[py])
        {
            parent[py]=px;
            rank[px]++;
        }
        return true;

    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        if (edges.size() != n - 1) return false;

        for (auto& edge : edges) {
            if (!uf._union(edge[0], edge[1])) {
                return false;
            }
        }
        return true;
    }
};
