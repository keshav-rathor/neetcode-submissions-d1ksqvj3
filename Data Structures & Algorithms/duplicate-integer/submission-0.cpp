// #include<iostream> 
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto x:nums)
        {
            // cout<<x<endl;
            if(map.find(x)!=map.end()) return true;
            else map[x]++;
        }
        return false;
    }
};
