class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto x:s)
        {
            if(x=='(' || x=='[' || x=='{' ) st.push(x);
            else
            {
                if(st.empty()) return false;
                if(st.top()=='(' && x!=')') return false;
                else if(st.top()=='{' && x!='}') return false;
                else if(st.top()=='[' && x!=']') return false;
                else 
                {
                    if(!st.empty()) st.pop();
                }

            }
        }
        if(!st.empty()) return false;
        return true;
        
    }
};
