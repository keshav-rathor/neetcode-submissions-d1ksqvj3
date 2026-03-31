class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solver(amount,coins,0,dp);
    }
    int solver(int target, vector<int>& nums,int i,vector<vector<int>>& dp)
    {
        int n=nums.size();
        if(i>=n || target<0) return 0;
        if(target==0) return 1;
        if(dp[i][target]!=-1) return dp[i][target];

        int taken=solver(target-nums[i],nums,i,dp);
        int not_taken=solver(target,nums,i+1,dp);
        return dp[i][target]=taken+not_taken;
    }
};
