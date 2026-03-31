class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);

        return min(solver(cost,0,dp),solver(cost,1,dp));
        
    }
    int solver(vector<int>& nums,int i,vector<int>& dp)
    {
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];


        int one=nums[i]+solver(nums,i+1,dp);
        int two=nums[i]+solver(nums,i+2,dp);
        return dp[i]=min(one,two);
    }
};
