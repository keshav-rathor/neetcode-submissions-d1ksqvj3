class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solver(board,word,i,j,0)) return true;
                }
            }

        }
        return false;
       
    }
    bool solver(vector<vector<char>>& board, string word,int i,int j,int ind)
    {
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[ind]) return false;

        if(ind>=word.size()-1) return true;
        board[i][j]='*';
        bool l=solver(board,word,i,j-1,ind+1);
        bool r=solver(board,word,i,j+1,ind+1);
        bool u=solver(board,word,i-1,j,ind+1);
        bool d=solver(board,word,i+1,j,ind+1);

        board[i][j]=word[ind];
        return l || r ||u || d;

    }
};
