class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        solver(n,0,0,"");
        return ans;
    }
    void solver(int n,int i,int j,string temp)
    {
        if(temp.size()==2*n)
        {
            ans.push_back(temp);
            return;
        }

        if(i<n)
        {
            temp+='(';
            solver(n,i+1,j,temp);
            temp.pop_back();
        }
        if(j<i)
        {
            temp+=')';
            solver(n,i,j+1,temp);
            temp.pop_back();

        }
    }

};
