class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans=0;
        for(auto x:nums) map[x]++;

        for(auto x:nums)
        {
            int temp=1;
            int dec=x-1;
            int inc=x+1;
            while(map[dec]>0)
            {
                temp++;
                dec--;
            }
            while(map[inc]>0)
            {
                temp++;
                inc++;
            }
            ans=max(ans,temp);
        }
        return ans;

    }
};
