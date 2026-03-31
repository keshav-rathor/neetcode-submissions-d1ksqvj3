class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> map;

        for(auto x:nums) map[x]++;

        for(auto x:map) pq.push({x.second,x.first});
        vector<int> ans;
        while(k)
        {
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
            k--;
        }
        return ans;

    }
};
