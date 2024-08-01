class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string s: details) {
            
            char a = s[11], b = s[12];
            string age = "";
            age += a;
            age += b;
            if(stoi(age) > 60) {
                ans++;
            }

        }

        return ans;
    }
};