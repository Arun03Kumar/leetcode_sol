class Solution {
public:
    bool recursive(string &s, int idx, int open_count) {
        if(idx == s.size()) return open_count == 0;

        bool is_valid = false;
        if(s[idx] == '(') {
            is_valid |= recursive(s, idx + 1, open_count + 1);
        }
        else if(s[idx] == '*') {
            is_valid |= recursive(s, idx + 1, open_count + 1);
            is_valid |= recursive(s, idx + 1, open_count);
            if(open_count > 0) is_valid |= recursive(s, idx + 1, open_count - 1);  
        }
        else {
            if(open_count > 0) is_valid |= recursive(s, idx + 1, open_count - 1);
        }

        return is_valid;
    }

    bool memoization(string &s, vector<vector<int>> &dp, int idx, int open_count) {
        if(idx == s.size()) return open_count == 0;

        if(dp[idx][open_count] != -1) return dp[idx][open_count];

        bool is_valid = false;
        if(s[idx] == '(') {
            is_valid |= memoization(s, dp, idx + 1, open_count + 1);
        }
        else if(s[idx] == '*') {
            is_valid |= memoization(s, dp, idx + 1, open_count + 1);
            is_valid |= memoization(s, dp, idx + 1, open_count );
            if(open_count > 0) is_valid |= memoization(s, dp, idx + 1, open_count - 1);
        }
        else {
            if(open_count > 0) is_valid |= memoization(s, dp, idx + 1, open_count - 1);
        }

        return dp[idx][open_count] = is_valid;
    }

    bool checkValidString(string s) {
        // Approach 1: Recursive
        // return recursive(s, 0, 0);

        // Approach 2: Memoization
        // int n = s.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return memoization(s, dp, 0, 0);


        // Approach 3: Bottom-up
        // int n = s.size();
        // vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        // dp[n][0] = true; // when there is empty string and no open brackets then it will be true this is our base case

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int open = 0; open <= n; open++) {

        //         bool is_valid = false;
        //         if(s[i] == '(') {
        //             is_valid |= dp[i + 1][open + 1];
        //         }
        //         else if(s[i] == '*') {
        //             is_valid |= dp[i + 1][open + 1];
        //             is_valid |= dp[i + 1][open];
        //             if(open > 0) is_valid |= dp[i + 1][open - 1];
        //         }
        //         else {
        //             if(open > 0) is_valid |= dp[i + 1][open - 1];
        //         }

        //         dp[i][open] = is_valid;
        //     }

        // }

        // return dp[0][0];



        // Approach 4: stack(wrong approach)
        // just maintain the count of *, if ')' came then check if top of stack is '(' then simply pop else if stack is empty but count of * till now is not 0 then it means * can be used as '('.

        // if we just do like this then all test cases won't pass because there is one possibility in which we have a  open bracket remaining in the array and also we have some * count [*(())(*] dry run this example
        // but we need to also check if the astrix came after that open bracket hence we need to also store the index and we need to store the * in another stack

        // int n = s.size();
        // stack<char> st;
        // int count = 0;

        // for(char &ch: s) {
        //     if(ch == '(') st.push(ch);
        //     else if(ch == ')') {
        //         if(st.empty() && count == 0) return false;
        //         else if(st.empty() && count != 0) {
        //             count--;
        //         }
        //         else {
        //             st.pop();
        //         }
        //     }
        //     else {
        //         count++;
        //     }
        // }

        // return st.empty();


        // stack correct approach
        int n = s.size();

        stack<int> bracket_st; // int to store the index 
        stack<int> astrix_st;

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') bracket_st.push(i);
            else if(s[i] == '*') astrix_st.push(i);
            else {
                // if both stack is empty 
                if(bracket_st.empty() && astrix_st.empty()) return false;
                // bracket stack is empty but astrix stack is not
                else if(bracket_st.empty() && !astrix_st.empty()) astrix_st.pop();
                else bracket_st.pop();
            }

        }

        while(!bracket_st.empty() && !astrix_st.empty()) {
            // if index of '(' is greater than then * index it means it * has came before the open bracket and it can't balance the open bracket.
            if(bracket_st.top() > astrix_st.top()) return false;

            bracket_st.pop();
            astrix_st.pop();
        }

        return bracket_st.empty();
    }
};