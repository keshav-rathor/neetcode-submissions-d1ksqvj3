class MinStack {
private:
    std::stack<int> valueStack; 
    std::stack<int> minStack;   

public:
    MinStack() {
    }
    
    void push(int val) {
        valueStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (valueStack.top() == minStack.top()) {
            minStack.pop();
        }
        valueStack.pop();
    }
    
    int top() {
        return valueStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
