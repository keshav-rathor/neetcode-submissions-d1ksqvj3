class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<int,int> map;
        int i=0;
        int j=0;
        int ans=0;
        int mx=0;

        while(j<n)
        {
            map[s[j]]++;
            mx=max(mx,map[s[j]]);
            while(j-i+1-mx>k)
            {
                map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};
