class MinStack {
public:
    // we can store a pair in the stack, first element is the input ans second element is the min element till now
    // so top of stack will always contains the minimum element
    // and we will always check if current input is smaller than the current minimum value in the stack or not

    stack<pair<int, int>> min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_st.empty()) min_st.push({val, val});
        else {
            int min_el_at_top = min_st.top().second;
            if(val < min_el_at_top) {
                min_st.push({val, val});
            }
            else {
                min_st.push({val, min_el_at_top});
            }
        }
    }
    
    void pop() {
        min_st.pop();
    }
    
    int top() {
        return min_st.top().first;
    }
    
    int getMin() {
       return min_st.top().second; 
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