class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(301,-1);
        unordered_map<string,int> map;
        for(auto x:wordDict) map[x]++;
        return solver(s,map,dp,0);
    }
    bool solver(string s,unordered_map<string,int> &map,vector<int> &dp,int i)
    {
        if(i==s.size()) return true;

        if(dp[i]!=-1) return dp[i];
        string temp="";
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(map.find(temp)!=map.end())
            {
                if(solver(s,map,dp,j+1)) return dp[i]=1;
            }
        }
        return dp[i]=0;

    }
};