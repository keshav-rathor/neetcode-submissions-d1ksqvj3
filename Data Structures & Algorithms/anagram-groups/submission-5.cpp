class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        int n=strs.size();

        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(auto x:strs[i])
            {
                freq[x-'a']++;
            }
            string temp="";
            for(auto x:freq) 
            {
                temp+=to_string(x);
                temp+="#";
            }
            map[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto x:map)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
