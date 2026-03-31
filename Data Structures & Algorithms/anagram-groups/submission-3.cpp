class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string,vector<string>> map;

        for(auto x:strs)
        {
            vector<int> temp(26);
            for(auto y:x)
            {
                temp[y-'a']++;
            }
            string key=to_string(temp[0]);
            for(int i=1;i<26;i++)
            {
                key+=','+to_string(temp[i]);
            }
            map[key].push_back(x);
        }
        for(auto x:map)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
