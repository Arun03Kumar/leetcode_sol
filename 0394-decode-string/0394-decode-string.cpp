class Solution {
public:
    string decodeString(string s) {
        stack<int> times;
        stack<string> words;

        string ans = "";
        int n = 0;
        for(char ch: s) {
            if(isdigit(ch)) {
                n = n * 10 + (ch - '0');
            }
            else if(ch == '[') {
                times.push(n);
                n = 0;
                words.push(ans);
                ans = "";
            }
            else if(ch == ']') {

                int k = times.top();
                times.pop();

                string temp2 = ans;
                ans = words.top();
                words.pop();

                while(k--) {
                    ans += temp2;
                }

            }   
            else {
                ans += ch;
            }
        }

        return ans;
    }
};