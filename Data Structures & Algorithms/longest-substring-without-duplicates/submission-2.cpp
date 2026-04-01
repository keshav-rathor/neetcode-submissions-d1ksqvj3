class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> map;
        int ans=0;

        int n=s.size();
        int i=0;
        int j=0;
        while(j<n)
        {
            map[s[j]]++;

            while(map.size()<j-i+1)
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
