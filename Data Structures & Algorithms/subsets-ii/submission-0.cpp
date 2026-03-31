class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;

        solver(nums,0,s,{});
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
    void solver(vector<int>& nums,int i,set<vector<int>>& s,vector<int> temp)
    {
        int n=nums.size();
        if(i>=n)
        {
            // vector<int> check=temp;
            sort(temp.begin(),temp.end());
            if(!s.count(temp)) s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solver(nums,i+1,s,temp);
        temp.pop_back();
        solver(nums,i+1,s,temp);
    }
};
