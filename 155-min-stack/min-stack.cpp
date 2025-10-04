class MinStack {
public:
    stack<long>stk;
    long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(0);
            mini = val;
        }else{
            stk.push(val - mini);
            mini = min(mini, (long)val);
        }
    }
    
    void pop() {
        long t =stk.top();
        stk.pop();
        if(t < 0) mini = mini - t;
    }
    
    int top() {
        long t = stk.top();

         return t > 0 ? mini +  t : mini;

    
    }
    
    int getMin() {
        return mini;
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