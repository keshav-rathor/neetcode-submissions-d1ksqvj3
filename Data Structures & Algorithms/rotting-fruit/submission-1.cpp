class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0;
        int ans=0;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(fresh>0 && !q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto top=q.front();
                q.pop();
                int x=top.first;
                int y=top.second;
                for(int j=0;j<4;j++)
                {
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx>=0 && ny>=0 && ny<m && nx<n && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        return fresh==0 ? ans:-1;
    }
};
