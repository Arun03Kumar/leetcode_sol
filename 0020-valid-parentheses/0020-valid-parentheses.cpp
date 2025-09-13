class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        // stack<char>
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
                stack.push_back(s[i]);
            }
            else {
                if(stack.empty()) return false;
                if(s[i] == ')' && stack.back() != '(') return false;
                else if(s[i] == ']' && stack.back() != '[') return false;
                else if(s[i] == '}' && stack.back() != '{') return false;
                stack.pop_back();
            }
        }

        if(stack.size() != 0) return false;
        return true;
    }

};