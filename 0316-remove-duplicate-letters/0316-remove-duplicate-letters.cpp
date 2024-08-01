class Solution {
public:
    string removeDuplicateLetters(string s) {

        // for each character in s we check if the top element in stack is larger than current element and frequency is larger than 0, it means we can add the top element after adding current element.
        // since we need to create lexicographically smaller string hence with this we are trying to add those elements after which can be came after.

        stack<char> st;
        vector<int> freq(26, 0);
        vector<bool> is_present(26, false);

        for(char c: s) {
            freq[c - 'a']++;
        }

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            freq[ch - 'a']--;

            if(is_present[ch - 'a'] == true) continue;

            while(!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0) {
                char top = st.top();
                is_present[top - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            is_present[ch - 'a'] = true;
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};