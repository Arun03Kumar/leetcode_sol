class Solution {
public:
    bool is_valid(string &s) {
        stack<char> st;

        for(char ch: s) {
            if(ch == '(') st.push(ch);
            else if(!st.empty() && st.top() == '(') st.pop();
            else st.push(ch);
        }

        return st.empty();
    }

    void recursion(string &curr, int n, vector<string> &ans) {
        if(curr.size() == 2 * n) {
            if(is_valid(curr)) ans.push_back(curr);

            return;
        }

        curr += "(";
        recursion(curr, n, ans);
        curr.pop_back();

        curr += ")";
        recursion(curr, n, ans);
        curr.pop_back();

    }

    vector<string> generateParenthesis(int n) {
        // Approach 1: Backtracking O(n * 2^n)
        // for each formed string with backtracking we also finding if that string is valid or not using stack
        // we can also not use stack and just maintain a variable if ( came then we add one else subtract one, so if we get overall sum to 0 then string is valid

        vector<string> ans;
        string curr = "";
        recursion(curr, n, ans);
        return ans;
    }
};