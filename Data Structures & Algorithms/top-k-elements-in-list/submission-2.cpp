class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto x:nums)
        {
            map[x]++;
        }
        for(auto x:map)
        {
            pq.push({x.second,x.first});
        }
        while(k--)
        {
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
