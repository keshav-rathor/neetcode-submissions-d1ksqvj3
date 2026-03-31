class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<char,int> map;
        int n=s.size();
        int i=0;
        int j=0;

        while(j<n)
        {
            map[s[j]]++;
            while(map[s[j]]>1)
            {
                map[s[i]]--;
                i++;
                if(map[s[i]]==0) map.erase(s[i]);
            }
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
        
    }
};
