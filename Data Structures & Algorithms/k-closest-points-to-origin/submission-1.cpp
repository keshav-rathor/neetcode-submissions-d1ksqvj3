class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;

        vector<vector<int>> ans;

        for(auto p:points) 
        {
            int dist=p[0]*p[0] + p[1]*p[1];
            cout<<p[0]<<"---"<<p[1]<<"---"<<dist<<endl;
            pq.push({-dist,{p[0],p[1]}});
        }

        for(int i=0;i<k;i++)
        {
            auto top=pq.top();
            pq.pop();
            int x=top.second.first;
            int y=top.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};
