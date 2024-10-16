class MyStack {
public:
    // since the element which came last should be on the top
    // but in queue if we push the next element it will came at the last
    // so when we want to push in stack we use second and empty queue and add the element into it so the element will be at the top
    // and we also check if first queue is empty or not if not then we have to push all the elemets from q2 to q1

    // and remaining operation we can use q1
    // becasue after each push we swap the q1 and q2
    queue<int> q1;
    queue<int> q2;

    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()) {
            int front = q1.front();
            q1.pop();

            q2.push(front);
        }

        swap(q1, q2);
    }
    
    int pop() {
       int front = q1.front();
       q1.pop();

       return front; 
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */