class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && (i==0 || j==0 || j==m-1 || i==n-1)  )
                {
                    solver(board,i,j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' )
                {
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='E' )
                {
                    board[i][j]='O';
                }
            }
        }


    }
    void solver(vector<vector<char>>& board,int i,int j)
    {
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O') return;
        board[i][j]='E';
        solver(board,i+1,j);
        solver(board,i-1,j);
        solver(board,i,j-1);
        solver(board,i,j+1);

    }
};
