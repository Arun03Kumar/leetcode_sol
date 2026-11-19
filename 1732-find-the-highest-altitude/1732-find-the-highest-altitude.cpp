class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // int n = gain.size();
        // vector<int> prefix(n, 0);
        // prefix[0] = gain[0];

        // for(int i = 1; i < n; i++) {
        //     prefix[i] = prefix[i - 1] + gain[i];
        // }

        // for(int x: prefix) {
        //     cout << x << " ";
        // }

        // int ans = 0;
        // for(int x: prefix) {
        //     ans = max(ans, x);
        // }

        // // for(int i = 0; i < n; i++) {
        // //     ans = max(ans, prefix[i]);
        // // }

        // return ans;

        int sum = 0;
        int ans = 0;

        for(int x: gain) {
            sum += x;
            ans = max(ans, sum);
        }

        return ans;
    }
};