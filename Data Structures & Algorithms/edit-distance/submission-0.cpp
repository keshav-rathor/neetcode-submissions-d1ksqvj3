class Solution {
public:
    int solver(int i,int j, string &s, string &t , vector<vector<int>>&dp)
    {
        if(i<0 ) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        // int taken=0;
        if(s[i]==t[j]) return dp[i][j]=solver(i-1,j-1,s,t,dp);
        int one=1+solver(i-1,j,s,t,dp);
        int two=1+solver(i,j-1,s,t,dp);
        int thr=1+solver(i-1,j-1,s,t,dp);
        return dp[i][j]=min({one,two,thr});


    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solver(n-1,m-1,word1,word2,dp);
    }
};