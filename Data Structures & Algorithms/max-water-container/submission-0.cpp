class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=INT_MIN;
        while(i<j)
        {
            ans=max(ans,(j-i)*min(nums[i],nums[j]));
            if(nums[i]<=nums[j]) i++;
            else j--;
        }
        return ans;

    }
};
