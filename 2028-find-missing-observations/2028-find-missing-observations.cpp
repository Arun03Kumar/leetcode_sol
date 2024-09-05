class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        
        int rem_sum = mean * (n + m) - sum;

        if(rem_sum < n or rem_sum > 6 * n) {
            return {};
        }

        int mean_rem = rem_sum / n;
        int mod = rem_sum % n;

        vector<int> ans(n, mean_rem);
        for(int i = 0; i < mod; i++) {
            ans[i]++;
        }

        return ans;

    }
};