class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int> s;
        for(auto x:nums) s.insert(x);
        for(int i=0;i<n;i++)
        {
            int count=0;
            int curr=nums[i];
            int prev=curr-1;
            if(!s.count(prev))
            {
                while(s.count(curr))
                {
                    curr++;
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
