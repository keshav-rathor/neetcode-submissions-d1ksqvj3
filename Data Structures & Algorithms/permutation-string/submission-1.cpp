class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> target(26);
        for(auto x:s1)
        {
            target[x-'a']++;
        }

        vector<int> s(26);
        int j=0;
        int i=0;

        
        while(j<s2.size())
        {
            s[s2[j]-'a']++;
            while(j-i+1>s1.size())
            {
                s[s2[i]-'a']--;
                i++;
            }
            if(j-i+1==s1.size() && s==target) return true;
            j++;
        }
        return false;
        
    }
};
