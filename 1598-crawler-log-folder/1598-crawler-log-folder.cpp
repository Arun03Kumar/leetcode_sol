class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string x: logs) {
            if(x[0] == '.' && x[1] == '.') {
                if(ans != 0)
                    ans -= 1;
            }
            else if(x[0] == '.' && x[1] == '/') continue;
            else ans += 1;
        }
        return ans;
    }
};