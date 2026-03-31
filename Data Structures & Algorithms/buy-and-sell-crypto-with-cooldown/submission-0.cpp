class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solver(prices,0,0,dp);
        
    }
    int solver(vector<int>& nums,int prev,int i,vector<vector<int>>& dp)
    {
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];

        int taken=0;
        if(prev==0) taken=-nums[i]+solver(nums,1,i+1,dp);
        if(prev==1) taken=nums[i]+solver(nums,0,i+2,dp);
        int not_taken=solver(nums,prev,i+1,dp);
        return dp[i][prev]=max(taken,not_taken);

    }
};
