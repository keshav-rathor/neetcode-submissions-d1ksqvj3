class Solution {
public:
    int maxScore(string s) {

        int n=s.size();

        int ans=0;

        for(int i=0;i<n-1;i++)
        {
            int zero=0;
            int one=0;

            for(int j=0;j<=i;j++)
            {
                if(s[j]=='0') zero++;
            }

            for(int j=i+1;j<n;j++)
            {
                if(s[j]=='1') one++;
            }

            ans=max(ans,one+zero);
        }
        return ans;
        
    }
};