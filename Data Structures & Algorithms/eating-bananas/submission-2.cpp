class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());

        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(check(piles,h,mid))
            {
                high=mid-1;
                ans=mid;

            }
            else low=mid+1;

        }
        return ans;
    }
    bool check(vector<int>& piles, int h,int k)
    {
        int sum=0;

        for(auto x:piles)
        {
            sum+=x/k;
            if(x%k!=0) sum++;

        }
        if(sum>h) return false;
        return true;
    }
};
