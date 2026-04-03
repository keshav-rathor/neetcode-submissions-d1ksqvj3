class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n=stones.size();
        if(n==1) return stones[0];

        for(auto x:stones) pq.push(x);
        int ans=0;

        while(true)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(pq.empty())
            {
                ans=x-y;
                break;
            }
            pq.push(x-y);
        }
        return ans;
        
    }
};
