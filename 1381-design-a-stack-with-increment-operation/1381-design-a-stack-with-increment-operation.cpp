class CustomStack {
public:
    vector<int> st;
    int size;
    int top;

    CustomStack(int maxSize) {
        size = maxSize;
        st.resize(size);
        top = -1;
    }
    
    void push(int x) {
        top++;
        if(top < size) {
            st[top] = x;
        }
        for(int x: st) cout << x << " ";
        cout << endl;
    }
    
    int pop() {
        if(top == size) top--;
        if(top >= 0 && top <= size) {
            int temp = st[top];
            st[top] = 0;
            top--;
            for(int x: st) cout << x << " ";
            cout << endl;
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int i = 0;
        for(int x: st) cout << x << " ";
        cout << endl;
        k = min(k, top);
        while(k--) {
            st[i] += val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */