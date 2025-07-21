class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int count = 1;
        string ans;
        ans += prev;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == prev) {
                count++;
            }
            else {
                count = 1;
                prev = s[i];
            }

            if(count <= 2) {
                ans += s[i];
            }
        }

        return ans;
    }
};