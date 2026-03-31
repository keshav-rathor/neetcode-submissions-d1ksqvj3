class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int> map;
        int i=0,j=0;

        while(j<n)
        {
            map[s[j]]++;

            while(map[s[j]]>1)
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
