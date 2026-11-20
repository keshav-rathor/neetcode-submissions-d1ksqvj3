class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX;
        int ans=0;

        for(auto x:prices)
        {
            
            ans=max(ans,x-low);
            low=min(low,x);
        }
        return ans;

        
    }
};
