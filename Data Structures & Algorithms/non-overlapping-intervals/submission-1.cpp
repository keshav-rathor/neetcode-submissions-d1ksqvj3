class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        // cout<<points[1][1]<<endl;
       int lastpoint = nums[0][1];

       for(auto it : nums)
       {
            if(it[0]>=lastpoint)
            {
                ans++;
                lastpoint = it[1];
            }
            lastpoint = min(lastpoint,it[1]);
       }
       return nums.size()-ans;
    }
};
