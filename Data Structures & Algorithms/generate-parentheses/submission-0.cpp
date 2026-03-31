class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        solver(n,ans,temp,0,0);
        return ans;
    }
    void solver(int n,vector<string> &ans,string temp,int i,int j)
    {
        if(temp.size()==2*n) 
        {
            ans.push_back(temp);
            return;
        }
        if(i<n)
        {
            temp+='(';
            solver(n,ans,temp,i+1,j);
            temp.pop_back();
        }
        if(j<i)
        {
            temp+=')';
            solver(n,ans,temp,i,j+1);
            temp.pop_back();
        }

        
    }
};