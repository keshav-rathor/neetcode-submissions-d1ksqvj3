class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        
        solver(nums,ans,0,{});
        return ans;
    }
    void solver(vector<int > &nums,vector<vector<int>>& ans,int i,vector<int> temp)
    {
        int n=nums.size();
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solver(nums,ans,i+1,temp);
        temp.pop_back();
        solver(nums,ans,i+1,temp);
    }
};
