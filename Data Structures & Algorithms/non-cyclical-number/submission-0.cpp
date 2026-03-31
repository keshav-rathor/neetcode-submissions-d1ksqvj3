class Solution {
public:
    bool isHappy(int n) {
        set<int> s;

        while(n!=1)
        {
            
            if(s.count(n)) return false;
            s.insert(n);
            int ans=0;
            while(n>0)
            {
                int sq=n%10;
                ans+=(sq*sq);
                n/=10;
            }
            n=ans;
            cout<<n<<endl;
        }
        return true;
        
    }
};
