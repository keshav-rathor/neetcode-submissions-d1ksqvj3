class Solution {
public:
    // int ans=0;
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        return solver(text1,text2,0,0,dp);
    }

    int solver(string s1, string s2,int i,int j,vector<vector<int>> &dp)
    {
        int n=s1.size();
        int m=s2.size();
        if(i>=n || j>=m)
        {
            // ans=max(ans,curr);
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int take=0;
        if(s1[i]==s2[j])
        {
            take=1+solver(s1,s2,i+1,j+1,dp);
        }
        int not_take=max(solver(s1,s2,i+1,j,dp),solver(s1,s2,i,j+1,dp));

        return dp[i][j]=max(take,not_take);
    }
};
