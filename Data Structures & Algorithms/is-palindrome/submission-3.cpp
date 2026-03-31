class Solution {
public:
    bool isPalindrome(string s) {


        int n=s.size();
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            char x=tolower(s[i]);
            char y=tolower(s[j]);
            // cout<<x<<"---"<<y<<" s[i]--"<<s[i]<<" s[j]---"<<s[j]<<endl;
            cout<<isalpha(x) <<"---"<< isalpha(y)<<endl;
            if(isalnum(x) && isalnum(y))
            {
                cout<<"I am here--"<<endl;
                if(x!=y) return false;
                
                i++;
                j--;

            }
            else if(!isalnum(x)) i++;
            else if(!isalnum(y)) j--;

        }
        return true;
        
    }
};
