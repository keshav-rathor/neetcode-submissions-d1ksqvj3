class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int> map;
        int i=0;
        int j=0;
        int mx=0;
        while(j<n)
        {
            map[s[j]]++;
            mx=max(mx,map[s[j]]);
            while(j-i+1-mx>k)
            {
                map[s[i]]--;
                i++;
                if(map[s[i]]==0) map.erase(s[i]);
            }
            if(j-i+1-mx<=k) ans=max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};
