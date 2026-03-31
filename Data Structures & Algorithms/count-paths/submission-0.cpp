class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         ans+=solver(n,m,i,j,ans,dp);
        //     }
        // }
        return solver(n,m,0,0,dp);;
        
    }
    int solver(int n,int m,int i,int j,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || j>=m || i>=n) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        take+=(solver(n,m,i+1,j,dp)+solver(n,m,i,j+1,dp));
        return dp[i][j]=take;

    }
};
