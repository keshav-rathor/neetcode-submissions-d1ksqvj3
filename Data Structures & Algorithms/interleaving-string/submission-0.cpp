class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if(n1+n2!=n3) return false;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solver(s1,s2,s3,0,0,0,dp);
    }
    bool solver(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>> &dp)
    {
        if(k>=s3.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];

        bool flag1=false;
        bool flag2=false;
        if(s1[i]==s3[k])
        {
            flag1=solver(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s2[j]==s3[k])
        {
            flag2=solver(s1,s2,s3,i,j+1,k+1,dp);
        }
        return flag1 || flag2;


    }
};
