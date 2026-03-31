class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solver(nums,target,ans,0,curr);
        return ans;
    }
    void solver(vector<int>& nums, int target,vector<vector<int>> &ans,int i,vector<int> curr)
    {
        int n=nums.size();

        if(i>=n || target<0)
        {
            return;

        }
        if(target==0) 
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solver(nums,target-nums[i],ans,i,curr);
        curr.pop_back();
        solver(nums,target,ans,i+1,curr);



    }
};
