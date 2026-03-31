class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        while(pq.size()>1 )
        {
            int val1=pq.top();
            pq.pop();
            int val2=pq.top();
            pq.pop();
            int val=max(val1,val2)-min(val1,val2);
            pq.push(val);
        }

        
        return pq.top();

        
    }
};
