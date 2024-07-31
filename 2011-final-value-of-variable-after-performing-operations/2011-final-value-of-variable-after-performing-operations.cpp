class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        for(string x: operations) {
            if(x[0] == '-') ans--;
            else if(x[0] == '+') ans++;
            else {
                if(x[0] == 'X' && x[1] == '+') ans++;
                else ans--;
            }
        }

        return ans;
    }
};