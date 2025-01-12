class Solution {
public:
    bool canBeValid(string s, string locked) {
        // Approach 1: using stack
        // as we normally do in balancing parenthesis,if we get open bracket push into stack but here we have to check if it is not flexible
        // if it is flexible then push into another stack
        // if we get open bracket the we need flexible bracket at index which is greater than current hence we need to store index in the stack

        int n = s.size();
        if(n % 2 != 0) return false;

        stack<int> open, flexible;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') {
                flexible.push(i);
            }
            else if(s[i] == '(') {
                open.push(i);
            }
            else {
                // if we get close bracket then we check first if we have any open brackets in the stack if yes then pop that else we can check in flexible to balance that, if not means it can't be balanced
                if(!open.empty()) {
                    open.pop();
                }
                else if(!flexible.empty()) {
                    flexible.pop();
                }
                else {
                    return false;
                }
            }
        }

        // if both open and flexible stacks are not empty()
        // since open only contains open bracket so to balance this we need a closing brackets at greater index than this so we need to check if flexible contains any such index
        while(!open.empty() && !flexible.empty() && open.top() < flexible.top()) {
            open.pop();
            flexible.pop();
        }

        // if open is empty it means flexible will also empty or contains even number of elements which can be balanced
        return open.empty();
    }
};