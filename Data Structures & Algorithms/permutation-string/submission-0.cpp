class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> temp(26);
    
        for(int j=0;j<s1.size();j++) temp[s1[j]-'a']++;
        if(s2.size()<s1.size()) 
        {
            cout<<"Is it you:--"<<endl;
            return false;
        }
        int i=0;
        int j=0;
        vector<int> s(26);
       
        while(j<s2.size())
        {
            s[s2[j]-'a']++;
            while(j-i+1>s1.size())
            {
                s[s2[i]-'a']--;
                i++;
            }
            if(j-i+1==s1.size()) if(s==temp) return true;
            
            j++;
            
            
        }
        return false;
        
        
    }
};
