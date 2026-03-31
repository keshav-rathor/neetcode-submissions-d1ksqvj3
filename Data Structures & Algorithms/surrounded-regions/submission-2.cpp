class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O') q.push({i,0});
        }
        
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O') q.push({0,i});
        }
        for(int i=0;i<m;i++)
        {
            if(board[n-1][i]=='O') q.push({n-1,i});
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O') q.push({i,m-1});
        }
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;

            mat[x][y]=1;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O' && mat[nx][ny]==0)
                {
                    q.push({nx,ny});
                }
            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0) board[i][j]='X';
            }
        }
        return;

        
    }
};
