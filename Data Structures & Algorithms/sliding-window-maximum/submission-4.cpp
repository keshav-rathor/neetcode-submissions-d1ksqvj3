class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int> s;
        vector<int> ans;
        unordered_map<int, int> map;
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        while(j < n) {
            map[nums[j]]++;
            s.insert(nums[j]);
            
            if(j - i + 1 > k) {
                map[nums[i]]--;
                if(map[nums[i]] == 0) {
                    map.erase(nums[i]);
                    s.erase(nums[i]);
                }
                i++;
            }
            
            if(j - i + 1 == k) {
                int last = *s.rbegin();
                ans.push_back(last);
            }
            
            j++;
        }
        return ans;
    }
};
