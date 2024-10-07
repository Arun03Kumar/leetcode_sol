class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int i = 0;

        while(i < s.size()) {
            if(s[i] == 'A') {
                if(i + 1 < s.size() && s[i + 1] == 'B') {
                    s.erase(i, 2);
                    cout << s << endl;
                    if(i - 1 < 0) {
                        i = 0;
                    }
                    else {
                        i--;
                    }
                }
                else {
                    i++;
                }
            }
            else if(s[i] == 'C') {
                if(i + 1 < s.size() && s[i + 1] == 'D') {
                    s.erase(i, 2);
                    cout << s << endl;
                    if(i - 1 < 0) {
                        i = 0;
                    }
                    else {
                        i--;
                    }
                }
                else {
                    i++;
                }
            }
            else {
                i++;
            }
        }

        return s.size();
    }
};