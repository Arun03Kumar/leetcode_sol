class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zero(n, 0), ones(n, 0);

        if(s[0] == '0') zero[0] = 1;
        if(s[n - 1] == '1') ones[n - 1] = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == '0') zero[i] = zero[i - 1] + 1;
            else zero[i] = zero[i - 1];
        }

        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == '1') ones[i] = ones[i + 1] + 1;
            else ones[i] = ones[i + 1];
        }

        for(int &x: ones) cout << x << " ";
        cout << endl;
        for(int &x: zero) cout << x << " ";

        int ans = 0;
        for(int i = 0; i < zero.size() - 1; i++) {
            int temp = (i == n - 1) ? 0 : ones[i + 1];
            ans = max(ans, zero[i] + temp);
        }

        return ans;
    }
};