class Solution {
public:
    int missingNumber(vector<int>& nums) {

        unordered_map<int,int> map;

        int n=nums.size();
       

        for(auto i:nums) map[i]++;
        for(int i=0;i<=n;i++)
        {
            if(map.find(i)==map.end()) return i;

        }
        return -1;
        
    }
};
