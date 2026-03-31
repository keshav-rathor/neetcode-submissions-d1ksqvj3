class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> ans;
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
            ans.push_back(top);
            for(auto x:adj[top])
            {
                indegree[x]--;
                if(indegree[x]==0) 
                {
                    
                    q.push(x);
                }
            }
        }
        // if(!q.empty()) return false;
        // for(auto x:indegree) if(x>0) return ;

        if(ans.size()==n) return ans;
        return {};
        // return solver(n,adj,vis,0);
    }
};
