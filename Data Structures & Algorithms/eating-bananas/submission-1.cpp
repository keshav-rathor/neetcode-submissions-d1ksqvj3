class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();
        int low=1;
        int high=1e9+7;

        int ans=0;
        while(low<high)
        {
            int mid=(low+high)/2;

            if(check(nums,h,mid))
            {
                ans=mid;
                high=mid;
            }
            else low=mid+1;
        }
        return high;
    }
    bool check(vector<int>& nums,int h,int mid)
    {
        int count=0;
        for(auto x:nums)
        {
            // cout<<mid<<" x/mid----"<<x/mid<<endl;
            count+=(x/mid);
            if(x%mid!=0) count+=1;
        }
        // cout<<mid<<"----"<<count<<endl;
        if(count<=h) return true;
        return false;
    }
};
