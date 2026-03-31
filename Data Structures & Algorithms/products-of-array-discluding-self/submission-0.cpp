class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int product=1;
        for(auto x:nums)
        {
            if(x!=0) product*=x;
            else zero++;
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            if(x==0)
            {
                if(zero-1==0) ans[i]=product;
                else ans[i]=0;
            }
            else 
            {
                if(zero==0) ans[i]=product/nums[i];
                else ans[i]=0;
            }
        }
        return ans;
        


    }
};
