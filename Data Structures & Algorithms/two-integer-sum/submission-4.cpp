class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int n=nums.size();
        vector<int> ans;

        for(int i;i<n;i++)
        {
            if(map.find(target-nums[i])!=map.end())
            {
                return {map[target-nums[i]],i};
            }
            map[nums[i]]=i;

        }
        return {};

    }
};
