class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto x:nums)
        {
            if(map.find(x)!=map.end()) return true;
            map[x]++;
        }
        return false;

    }
};
