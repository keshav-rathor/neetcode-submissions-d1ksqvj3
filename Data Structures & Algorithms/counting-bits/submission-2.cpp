class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i=0;i<=n;i++)
        {
            int one=0;
            for(int j=0;j<32;j++)
            {
                bool bit=(i>>j) & 1;
                if(bit==1) one++;
            }
            ans.push_back(one);
        }
        return ans;
        
    }
};
