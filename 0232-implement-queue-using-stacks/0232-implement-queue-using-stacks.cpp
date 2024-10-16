class MyQueue {
public:
    // use two stacks one for input and one for output
    // when we get a query for input then push the input in to input array
    // and if query is pop, peek then use output stack, but also check if it is empty, if yes then transfer all elements to output from input stack
    stack<int> input, output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }

            int top = output.top();
            output.pop();

            return top;
        }
        else {
            int top = output.top();
            output.pop();

            return top;
        }
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }

            int top = output.top();
            // output.pop();

            return top;
        }
        else {
            int top = output.top();
            // output.pop();

            return top;
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
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