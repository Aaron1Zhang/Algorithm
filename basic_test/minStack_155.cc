class MinStack {
    stack<int> Min_Stack;
    stack<int> Stack;
public:
    MinStack() {

    }
    
    void push(int val) {
        Stack.push(val);
        if (Min_Stack.empty() || val <= Min_Stack.top()) {
            Min_Stack.push(val);
        }
    }
    
    void pop() {
        
        if (Stack.top() == Min_Stack.top()) {
            Min_Stack.pop();
        }
        Stack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return Min_Stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */