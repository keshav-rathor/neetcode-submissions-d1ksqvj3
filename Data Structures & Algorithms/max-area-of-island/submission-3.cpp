class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 )
                {
                    ans=max(ans,dfs(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || grid[i][j]==0) return 0;
        vis[i][j]=1;

        return (1+dfs(grid,i-1,j,vis)+dfs(grid,i+1,j,vis)+dfs(grid,i,j-1,vis)+dfs(grid,i,j+1,vis));
    }
};
