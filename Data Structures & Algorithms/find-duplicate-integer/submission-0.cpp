class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j]) 
                {
                    ans= nums[i];
                }
            }
        }
        return ans;
    }
};
