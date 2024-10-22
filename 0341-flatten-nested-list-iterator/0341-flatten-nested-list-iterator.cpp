/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    // we have given three interface to find if object is integer or NestedInteger this can be checked with isInteger() function
    // if it gives true then we can use getInteger to get the integer
    // we can use getList() to get vector of all objects inside the object

    // for any flattening questions we can use stack or recursion
    // it is given in the question that first hasNext() would be called if it returns true then next() will be called
    // so during object initialization we have to push all the objects inside the stack but we want numbers from start so we have to append them in reverse direction
    // we are making sure that top of stack always contains an integer value if not then we flatten the nested and make it integer

    // but this way we are creating copy if given array in the constructor ans since it is a class so it will take a lot of memory
    // to reduce the memory we can store the reference of those objects and then we can access them using arrow

    // // stack<NestedInteger> st;

    // NestedIterator(vector<NestedInteger> &nestedList) {
    //     int n = nestedList.size();
    //     for(int i = n - 1; i >= 0; i--) {
    //         st.push(nestedList[i]);
    //     }
    // }
    
    // int next() {
    //     int top = st.top().getInteger();
    //     st.pop();

    //     return top;
    // }
    
    // bool hasNext() {
    //     if(st.empty()) return false;

    //     while(!st.empty()) {
    //         NestedInteger top = st.top();
            
    //         if(top.isInteger()) return true;

    //         st.pop();
    //         vector<NestedInteger> vec = top.getList();
    //         for(int i = vec.size() - 1; i >= 0; i--) {
    //             st.push(vec[i]);
    //         }
    //     }

    //     return false;
    // }

    stack<NestedInteger*> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n - 1; i >= 0; i--) {
            st.push(&nestedList[i]);
        }
    }
    
    int next() {
        int top = st.top() -> getInteger();
        st.pop();

        return top;
    }
    
    bool hasNext() {
        if(st.empty()) return false;

        while(!st.empty()) {
            NestedInteger* top = st.top();
            
            if(top -> isInteger()) return true;

            st.pop();

            // since interface is returning const hence we have to use &vec to store it
            vector<NestedInteger> &vec = top -> getList();
            for(int i = vec.size() - 1; i >= 0; i--) {
                st.push(&vec[i]);
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */