class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        int carry=1;
        for(int i=n-1;i>=0;i--)
        {
            int val=carry+digits[i];
            ans.push_back(val%10);
            carry=val/10;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;


    }
};
