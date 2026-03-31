class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set<int> s_row;
        set<int> s_col;


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    s_row.insert(i);
                    s_col.insert(j);
                }
            }
        }

        for(auto x:s_row)
        {
            for(int j=0;j<m;j++)
            {
                matrix[x][j]=0;
            }
        }
        for(auto x:s_col)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][x]=0;
            }
        }
        
    }
};
