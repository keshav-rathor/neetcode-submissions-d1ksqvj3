class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& it) {
        vector<vector<int>> ans;
        nums.push_back(it);
        sort(nums.begin(),nums.end());
        for(auto x:nums)
        {
            if(ans.size()==0 || x[0]>ans.back()[1]) ans.push_back(x);
            else 
            {
                vector<int> temp=ans.back();
                ans.pop_back();
                ans.push_back({temp[0],max(x[1],temp[1])});
            }
            
        }
        return ans;
    }
};