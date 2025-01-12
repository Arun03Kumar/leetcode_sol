class Solution {
public:
    bool canBeValid(string s, string locked) {
        // // Approach 1: using stack
        // // as we normally do in balancing parenthesis,if we get open bracket push into stack but here we have to check if it is not flexible
        // // if it is flexible then push into another stack
        // // if we get open bracket the we need flexible bracket at index which is greater than current hence we need to store index in the stack

        // int n = s.size();
        // if(n % 2 != 0) return false;

        // stack<int> open, flexible;

        // for(int i = 0; i < n; i++) {
        //     if(locked[i] == '0') {
        //         flexible.push(i);
        //     }
        //     else if(s[i] == '(') {
        //         open.push(i);
        //     }
        //     else {
        //         // if we get close bracket then we check first if we have any open brackets in the stack if yes then pop that else we can check in flexible to balance that, if not means it can't be balanced
        //         if(!open.empty()) {
        //             open.pop();
        //         }
        //         else if(!flexible.empty()) {
        //             flexible.pop();
        //         }
        //         else {
        //             return false;
        //         }
        //     }
        // }

        // // if both open and flexible stacks are not empty()
        // // since open only contains open bracket so to balance this we need a closing brackets at greater index than this so we need to check if flexible contains any such index
        // while(!open.empty() && !flexible.empty() && open.top() < flexible.top()) {
        //     open.pop();
        //     flexible.pop();
        // }

        // // if open is empty it means flexible will also empty or contains even number of elements which can be balanced
        // return open.empty();




        // Approach 2: without extra space
        // we can use two pass validation means check from left to right and from right to left
        // so when we tranverse from left to right we increase count of open brackets and when we get closing brackets we decrease count of open brackets, but since here we also have flexible case
        // so we want to always increase open count if we get flexible because we never want our count to be -ve beacuse it tells that it can't be balanced
        // ()) here => +1 -1 -1, at third index we get -ve open count so we return false 

        int n = s.size();
        if(n % 2 != 0) return false;

        int open = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || locked[i] == '0') open++;
            else open--;

            if(open < 0) return false;
        }

        int close = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')' || locked[i] == '0') close++;
            else close--;

            if(close < 0) return false;
        }

        return true;
    }
};