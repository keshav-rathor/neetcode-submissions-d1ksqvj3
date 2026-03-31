class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        // vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' )
                {
                    solver(grid,i,j);

                    ans++;
                }
            }
        }
        return ans;

    }
    void solver(vector<vector<char>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || grid[i][j]=='2') return;
        grid[i][j]='2';
        solver(grid,i+1,j);
        solver(grid,i-1,j);
        solver(grid,i,j+1);
        solver(grid,i,j-1);

    }
};
