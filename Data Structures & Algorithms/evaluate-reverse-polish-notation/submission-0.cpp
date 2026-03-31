class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                
                if (token == "+") {
                    stk.push(num1 + num2);
                } else if (token == "-") {
                    stk.push(num1 - num2);
                } else if (token == "*") {
                    stk.push(num1 * num2);
                } else if (token == "/") {
                    stk.push(num1 / num2);
                }
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};
