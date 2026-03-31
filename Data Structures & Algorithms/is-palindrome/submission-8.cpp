class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
       
        
        string str="";
        for(auto x:s)
        {
            if(isalnum(x)) str+=tolower(x);
        }
        int i=0;
        int j=str.size()-1;
        cout<<str<<endl;
        while(i<j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
        
    }
};
