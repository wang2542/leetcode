class MinStack {
public:
    /** initialize your data structure here. */
    // 辅助栈 记录最小值 同时操作
    stack<int> main_stack;
    stack<int> help_stack;
    MinStack() {
    }
    
    void push(int x) {
        main_stack.push(x);
        if (help_stack.empty()) {help_stack.push(x);}
        else {
            if (x < help_stack.top()) {
                help_stack.push(x);
            }
            else {
                int tmp = help_stack.top();
                help_stack.push(tmp);
            }
        } 
    }
    
    void pop() {
        main_stack.pop();
        help_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return help_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
