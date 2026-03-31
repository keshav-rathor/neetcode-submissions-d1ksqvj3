class Solution {
public:
    bool isPalindrome(string s) {

        string str="";

        for(auto x:s)
        {
            if(!isalnum(x) ) continue;
            str+=tolower(x);
        }
        
        string rev=str;
        reverse(rev.begin(),rev.end());
        cout<<str<<endl;
        cout<<rev<<endl;
        if(str==rev) return true;
        
        return false;
    }
};
