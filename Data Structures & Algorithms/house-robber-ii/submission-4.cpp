class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);
        // int ans1=solver(nums,dp1,0,n-1);
        // int ans2=solver(nums,dp2,1,n);
        return max(solver(nums,dp,0,n-1),solver(nums,dp2,1,n));
    }
    int solver(vector<int>& nums,vector<int> &dp,int i,int end)
    {
        int n=nums.size();
        if(i>=end) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int taken=nums[i]+solver(nums,dp,i+2,end);
        int not_taken=(solver(nums,dp,i+1,end));
        return dp[i]=max(taken,not_taken);
    }
};