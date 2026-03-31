class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(n<t.size()) return "";
        unordered_map<char,int> map;
        for(auto x:t) map[x]++;
        int i=0;
        int j=0;
        // string ans=s;
        // unordered_map<char,int> temp=map;
        int len=INT_MAX;
        int start=0;
        int count=t.size();
        while(j<n)
        {
            if(map[s[j]]>0) count--;
            map[s[j]]--;
            j++;
            while(count==0)
            {
                if(j-i<len)
                {
                    start=i;
                    len=j-i;
                }
                map[s[i]]++;
                if(map[s[i]]>0) count++;
                i++;
            }
            
        }
        if(len!=INT_MAX) return s.substr(start,len);
        return "";

    }
};
