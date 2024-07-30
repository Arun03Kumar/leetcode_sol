class Solution {
public:
    int minimumDeletions(string s) {

        // when we get a 'b' at the top of stack and our current character is 'a' then we need to remove these two characters from the stack, since we didn't even push the current character yet so just pop the top character in to the stack.

        // stack<char> st;

        // int i = 0, count = 0;
        // while(i < s.size()) {
        //     // char top = st.top();
        //     char curr = s[i];

        //     if(!st.empty() && (curr == 'a' && st.top() == 'b')) {
        //         st.pop();
        //         count++;
        //     }
        //     else {
        //         st.push(curr);
        //     }
        //     i++;
        // }

        // return count;


        // Approach 2: O(1) solution

        // in this we are trying to remove all the b's on the left side of an index and all the a's from the right side of the index, so we need a frequency array for both but we can reduce it to just a variable.

        // in starting we count all the numbers of a and on each iteration we remove one if current element is 'a' and add to the b's variable if it is 1.

        int right_a = 0;
        int left_b = 0;

        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == 'a') {
                right_a++;
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'a') right_a--;

            ans = min(ans, right_a + left_b);

            if(s[i] == 'b') left_b++;

        }

        return ans;
    }
};