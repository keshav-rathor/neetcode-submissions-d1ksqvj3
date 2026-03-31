class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));

        return solver(nums,-1,0,dp);
    }
    int solver(vector<int>& nums,int prev,int i,vector<vector<int>> &dp)
    {
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        int take=0;
        if(prev==-1 || prev!=i-1)
        {
            take=nums[i]+solver(nums,i,i+1,dp);
        }
        int not_take=solver(nums,prev,i+1,dp);

        return dp[prev+1][i]=max(take,not_take);
    }
};
