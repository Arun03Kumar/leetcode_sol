class MyQueue {
public:
    stack<int> st1, st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);

        while(!st1.empty()) {
            int top = st1.top();
            st1.pop();

            st2.push(top);
        } 

        swap(st1, st2);
    }
    
    int pop() {
       int top = st1.top();
       st1.pop();

       return top; 
    }
    
    int peek() {
       return st1.top(); 
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */