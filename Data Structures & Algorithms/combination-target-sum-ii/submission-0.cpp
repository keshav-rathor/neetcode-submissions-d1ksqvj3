class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        

        solver(nums,target,ans,{},0);
        for(auto x:s) ans.push_back(x);
        return ans;
    }
    void solver(vector<int>& nums,int target,vector<vector<int>>& ans,vector<int> temp,int i)
    {
        int n=nums.size();
        if(target==0)
        {
            // ans.push_back(temp);
            // return;
            sort(temp.begin(),temp.end());
            if(!s.count(temp)) s.insert(temp);
            return;
        }
        if(i>=n || target<0)
        {
            return;
        }
        
        temp.push_back(nums[i]);
        // target=target-nums[i];
        solver(nums,target-nums[i],ans,temp,i+1);
        // target=target+nums[i];
        temp.pop_back();
        solver(nums,target,ans,temp,i+1);

    }
};
