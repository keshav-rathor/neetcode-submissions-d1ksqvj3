class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> map;
        for(auto x:nums)
        {
            map[x]++;
        }

        int ans=0;
        int len=0;

        for(auto x:nums)
        {
            int curr=x;
            if(map.find(curr-1)==map.end())
            {
                // int curr=x;
                while(map.find(curr)!=map.end())
                {
                    len++;
                    curr++;
                }
                ans=max(ans,len);
                len=0;
            }

        }
        return ans;

        
    }
};
