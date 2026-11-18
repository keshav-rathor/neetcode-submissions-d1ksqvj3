class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    solver(grid,i,j);
                    ans+=1;
                }
            }
        }
        return ans;
    }
    void solver(vector<vector<char>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 ||i>=n || j<0 || j>=m || grid[i][j]=='2' || grid[i][j]=='0') return ;
        grid[i][j]='2';
        solver(grid,i,j-1);
        solver(grid,i,j+1);
        solver(grid,i-1,j);
        solver(grid,i+1,j);
    }
};
