class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        // vector<int> vis(n,0);
        for(auto x:pre)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;

        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            cout<<indegree[i]<<endl;
            if(indegree[i]==0) q.push(i);
        }
        cout<<q.empty()<<endl;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            for(auto x:adj[top])
            {
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if(!q.empty()) return false;
        for(auto x:indegree) if(x>0) return false;
        return true;
        // return solver(n,adj,vis,0);
        
    }
    
};
