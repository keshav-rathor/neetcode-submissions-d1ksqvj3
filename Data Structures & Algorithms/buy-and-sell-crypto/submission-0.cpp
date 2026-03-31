class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX;
        int profit=0;
        for(auto x:prices)
        {
            low=min(low,x);
            profit=max(profit,x-low);
        }
        return profit;
    }
};
