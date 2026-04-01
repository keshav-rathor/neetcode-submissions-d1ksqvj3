class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_set<int> s_r;
        unordered_set<int> s_c;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    s_r.insert(i);
                    s_c.insert(j);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s_r.find(i)!=s_r.end() || s_c.find(j)!=s_c.end())
                {
                    matrix[i][j]=0;
                }
            }
        }

        
        
    }
};
