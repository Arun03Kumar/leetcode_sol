class Solution {
public:
    int minimumDeletions(string s) {

        // when we get a 'b' at the top of stack and our current character is 'a' then we need to remove these two characters from the stack, since we didn't even push the current character yet so just pop the top character in to the stack.

        stack<char> st;

        int i = 0, count = 0;
        while(i < s.size()) {
            // char top = st.top();
            char curr = s[i];

            if(!st.empty() && (curr == 'a' && st.top() == 'b')) {
                st.pop();
                count++;
            }
            else {
                st.push(curr);
            }
            i++;
        }

        return count;
    }
};