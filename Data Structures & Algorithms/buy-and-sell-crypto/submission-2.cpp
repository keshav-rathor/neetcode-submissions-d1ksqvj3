class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        int low=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            low=min(low,prices[i]);
            ans=max(ans,prices[i]-low);
        }
        return ans;
        
    }
};
