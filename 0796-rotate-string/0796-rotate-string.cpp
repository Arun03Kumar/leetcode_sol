class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        while(n--) {
            char c = s[0];
            s.erase(0, 1);
            s.push_back(c);
            cout << s << " ";
            if(s == goal) return true;
        }

        return false;
    }
};