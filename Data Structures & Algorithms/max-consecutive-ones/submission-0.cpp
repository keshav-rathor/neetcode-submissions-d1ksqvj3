class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        

        int n=nums.size();
        vector<int> ans(n);
        ans[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==1) ans[i]+=ans[i-1]+1;
            else ans[i]= nums[i];
        }
        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx,ans[i]);
        return mx;
        
    }
};