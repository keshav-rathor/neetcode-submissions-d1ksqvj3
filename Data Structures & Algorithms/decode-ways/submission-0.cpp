class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solver(s,0,dp);
    }
    int solver(string s,int i,vector<int> &dp)
    {
        int n=s.size();
        if(i>=n) return 1;

        if(dp[i]!=-1) return dp[i];
        int take=0;
        if(s[i]!='0') take+=solver(s,i+1,dp);
        if(i+1<n &&(s[i]=='1' || s[i]=='2' && s[i+1]<='6')) take+=solver(s,i+2,dp);
        return dp[i]=take;
    }
};


