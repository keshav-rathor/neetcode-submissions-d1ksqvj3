class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        return solver(n,dp);
        
    }
    int solver(int n,vector<int> &dp)
    {
        if(n<0) return 0;
        if(n==0) return 1;

        if(dp[n]!=-1) return dp[n];

        int one=solver(n-1,dp);
        int two=solver(n-2,dp);
        cout<<one<<endl;
        return dp[n]=one+two;
    }
};
