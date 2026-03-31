class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%2!=0) return false;
        int target=sum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solver(nums,0,target,dp);
        
    }
    bool solver(vector<int>& nums,int i,int target,vector<vector<int>>& dp)
    {
        int n=nums.size();
        if(i>=n || target<0) return false;
        if(target==0) return true;
        
        // if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];

        int take=solver(nums,i+1,target-nums[i],dp);
        int not_take=solver(nums,i+1,target,dp);
        return dp[i][target]=take || not_take; 


    }
};
